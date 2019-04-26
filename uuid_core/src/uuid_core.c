// uuid_core.c - Implementations of publicly-exposed library functions
//

#include "stdafx.h"
#include "uuid_core.h"

///////////////////////////////////////////////////////////////////////////////
// Internally-used functions

///////////////////////////////////////////////////////////////////////////////
// Externally-exposed functions

///////////////////////////////////////////////////////////////////////////////
// AreEqual function

BOOL AreEqual(UUID uuid1, UUID uuid2) {
    BOOL bResult = uuid_compare(uuid1, uuid2) == 0;
    return bResult;
}

///////////////////////////////////////////////////////////////////////////////
// GenerateNewUUID function

void GenerateNewUUID(UUID* pUUID) {
	// Must have an address in memory where
	// to copy the generated value to
	if (pUUID == NULL || *pUUID == NULL) {
		fprintf(stderr, UUID_NULL);
		exit(ERROR);
	}

	// generate
	uuid_generate_time_safe(*pUUID);
}

///////////////////////////////////////////////////////////////////////////////
// IsUUIDValid function

BOOL IsUUIDValid(UUID* pUUID) {
	// Must have an address in memory where the UUID
	// to be checked is sitting
	BOOL bResult = FALSE;
	if (pUUID == NULL || *pUUID == NULL) {
		return bResult; // NULL reference is not a valid UUID
	}

	bResult = !uuid_is_null(*pUUID);

	return bResult;
}

///////////////////////////////////////////////////////////////////////////////
// UUIDFromString function

void UUIDFromString(const char* pszUUID, UUID* pOutputUUID) {
	if (IsNullOrWhiteSpace(pszUUID)) {
		fprintf(stderr, UUID_BLANK);
		exit(ERROR);
	}

	if (pOutputUUID == NULL || *pOutputUUID == NULL) {
		fprintf(stderr, UUID_NULL);
		exit(ERROR);
	}

	uuid_parse(pszUUID, *pOutputUUID);
}

///////////////////////////////////////////////////////////////////////////////
// UUIDToString function

char* UUIDToString(UUID uuid) {
	char* pszResult = (char*) calloc(37, sizeof(char));
	if (pszResult == NULL) {
		fprintf(stderr, "Failed to allocate storage for UUID string.\n");
		exit(ERROR);
	}
	memset(pszResult, 0, 37);

	// unparse (to string)
	uuid_unparse_lower(uuid, pszResult);

	return pszResult;
}
