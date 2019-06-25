// uuid_core.h - Defines the public interface to the uuid_core library
//

#ifndef __UUID_CORE_H__
#define __UUID_CORE_H__

#include "uuid_core_symbols.h"

/* brings in the definition of the BOOL data type and other
 * API entities commonly utilized across my libraries. */
#include <../../api_core/api_core/include/api_core.h>

/**
 * @name AreUUIDsEqual
 * @brief Compares two UUIDs and determines whether they are equal.
 * @param pUUID1 Address of the first UUID value to compare.
 * @param pUUID2 Address of the second UUID value to compare.
 * @returns TRUE if the two UUIDs are the same value; FALSE otherwise.
 */
BOOL AreUUIDsEqual(UUID* pUUID1, UUID* pUUID2);

/**
 * @name CopyUUID
 * @brief Copies one UUID value to another.
 * @param pDestUUID Address of the UUID value that will receive the data.
 * @param pSrcUUID Address of the UUID value that has the data to be copied.
 * @remarks Makes the binary data in the array pointed to by pDestUUID match
 * the data in the array pointed to by pSrcUUID.
 */
void CopyUUID(UUID* pDestUUID, UUID* pSrcUUID);

/**
 * @name GenerateNewUUID
 * @brief Generates a new universally-unique identifier (UUID).
 * @param pUUID Address of a memory location that will receive the value
 * generated.  This must have a valid address value.
 */
void GenerateNewUUID(UUID* pUUID);

/**
 * @name IsUUIDValid
 * @brief Determines whether the UUID supplied is NULL or not.
 * @param pUUID Pointer to the UUID value to be checked.
 * @returns TRUE if the uuid variable has a valid value; FALSE otherise.
 */
BOOL IsUUIDValid(UUID* pUUID);

/**
 * @name UUIDFromString
 * @brief Given a string representation of a UUID, produces a data value.
 * @param pszUUID String representation of the UUID.
 * @param pOutputUUID Pointer to a buffer that receives the data value. Must
 * not be NULL.
 * @remarks String should be formatted "1b4e28ba-2fa1-11d2-883f-0016d3cca427\0"
 * or otherwise the output is not deterministic.
 */
void UUIDFromString(const char* pszUUID, UUID* pOutputUUID);

/**
 * @name UUIDToString
 * @brief Given a UUID value, puts its string representation into a char array.
 * @param pUUID Address of the UUID value to represent as a string.
 * @return Pointer to the first element of a char* buffer that contains the
 * string representation of the UUID provided.
 * @remarks An example value output is "1b4e28ba-2fa1-11d2-883f-0016d3cca427\0"
 * The output buffer is always 37 bytes long.  The memory whose address is
 * returned by this function must be freed with free().
 */
char* UUIDToString(UUID* pUUID);

#endif /* __UUID_CORE_H__ */
