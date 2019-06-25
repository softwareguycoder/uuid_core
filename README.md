# uuid_core
(Linux) C shared library for managing and manipulating Universally-Unique Identifiers (UUIDs)
## I. Introduction
The ```uuid_core``` library was created in order to provide a wrapper around the API for creating and manipulating [Universally-Unique Identifiers (UUIDs)](https://en.wikipedia.org/wiki/Universally_unique_identifier) in C under Linux.
### A. What is a Universally-Unique Identifier (UUID)?
According to Wikipedia,"A universally unique identifier (UUID) is a 128-bit number used to identify information in computer systems. The term globally unique identifier (GUID) is also used, typically in software created by Microsoft."  These identifiers are truly unique, as there are more possible combinations of values in them than there are stars in the entire Universe.

Furthmore, according to the same article, when generated according to the standard methods, UUIDs are for practical purposes unique, without depending for their uniqueness on a central registration authority or coordination between the parties generating them, unlike most other numbering schemes. While the probability that a UUID will be duplicated is not zero, it is close enough to zero to be negligible. 

### B. Obtaining shared libraries and headers for Linux
Support for UUID generation and manipulation is provided in Linux with the ```libuuid.so``` library, which can be obtained by doing ```sudo apt-get -y install uuid-dev``` in Bash.  The ```.cproject``` file (for use with Eclipse CDT) already contains settings used to link with this shared object library once it's installed with ```apt-get```.

### C. Dependencies
This library depends on the following libraries (besides ```libuuid.so```):
* api_core, at: https://github.com/softwareguycoder/api_core
* common_core, at: https://github.com/softwareguycoder/common_core
* exceptions_core, at: https://github.com/softwareguycoder/exceptions_core

The thinking in listing these is, that if you clone or fork this repo, it will be necessary to also clone and fork these other repos and ensure that the code is compiled/referenced by the server project in order for it to build.

## II. API Summary
The ```uuid_core``` library exposes the following functions and types:
### A. Types
The types exposed by ```uuid_core``` are:
* ```UUID``` - This is a ```typedef```-derived wrapper for the Linux ```uuid_t``` type (man page [here](https://linux.die.net/man/3/uuid)).
### B. Functions
The functions exposed by the ```uuid_core``` library are the following:
* ```AreUUIDsEqual``` - Tells if two ```UUID``` values are the same.
* ```CopyUUID``` - Copies one ```UUID``` value to another.
* ```GenerateNewUUID``` - Generates a new universally-unique identifier (UUID).
* ```IsUUIDValid``` - Determines whether the UUID supplied is NULL or not.
* ```UUIDFromString``` - Given a string representation, e.g., ```5cce2058-41d3-48e8-b3ae-35ef82eb2bb4```, of a UUID, produces a data value.
**NOTE:** Curly braces must not be present in the string representation.
* ```UUIDToString``` - Given a ```UUID``` value, puts its string representation into a char array.

## III. API Reference
### A. ```UUID``` type
#### Definition
```typedef uuid_t UUID;```

Typedef of a uuid_t symbol from the libuuid.so library.
#### Remarks
Meant to make code more readable.
### B. ```AreUUIDsEqual``` Function
#### Prototype
```BOOL AreUUIDsEqual(UUID* pUUID1, UUID* pUUID2);```

Compares two UUIDs and determines whether they are equal.
#### Parameters
*pUUID1* - Address of the first ```UUID``` value to compare.

*pUUID2* - Address of the second ```UUID``` value to compare.
#### Return values
This function returns nonzero if the two ```UUID```s are the same value; zero otherwise.
### C. ```CopyUUID``` Function
#### Prototype
```void CopyUUID(UUID* pDestUUID, UUID* pSrcUUID);```

Copies one UUID value to another.
#### Parameters
*pDestUUID* - Address of the ```UUID``` value that will receive the data.

*pSrcUUID* - Address of the ```UUID``` value that has the data to be copied.
#### Remarks
Makes the binary data in the array pointed to by ```pDestUUID``` match the data in the array pointed to by ```pSrcUUID```.
### D. ```GenerateNewUUID``` Function
#### Prototype
```void GenerateNewUUID(UUID* pUUID);```

Generates a new universally-unique identifier (UUID).
#### Parameters
*pUUID* - Address of a memory location that will receive the value generated.  This must have a valid address value.

#### Remarks
The ```pUUID``` parameter must not be set to ```NULL```.  If it is, an error message will be displayed and the calling application will be forcibly terminated.
### E. ```IsUUIDValid``` Function
#### Prototype
```BOOL IsUUIDValid(UUID* pUUID);```

Determines whether the UUID supplied is NULL or not.
#### Parameters
*pUUID* - Pointer to the ```UUID``` value to be checked.

#### Return values
Nonzero if the ```UUID``` variable has a valid value; zero otherise.
### F. ```UUIDFromString``` Function
#### Prototype
```void UUIDFromString(const char* pszUUID, UUID* pOutputUUID);```

Given a string representation of a ```UUID```, e.g., ```5cce2058-41d3-48e8-b3ae-35ef82eb2bb4```, produces a data value.
#### Parameters
*pszUUID* - String representation of the UUID.
*pOutputUUID* - Pointer to a buffer that receives the data value. Must not be ```NULL```.

#### Remarks
String should be formatted, e.g., ```"1b4e28ba-2fa1-11d2-883f-0016d3cca427\0"``` or otherwise the output is not deterministic.
### F. ```UUIDToString``` Function
#### Prototype
```char* UUIDToString(UUID* pUUID);```

Given a ```UUID``` value, puts its string representation into a char array.
#### Parameters
*pUUID* - Address of the ```UUID``` value to represent as a string.

#### Return values
Address of the first element of a ```char*``` buffer that contains the string representation of the UUID provided.

#### Remarks
An example value output is ```"1b4e28ba-2fa1-11d2-883f-001 6d3cca427\0"```. The output buffer is always 37 bytes long.  The memory whose address is returned by this function must be freed with ```free()```.
