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

BOOL AreEqual(UUID* pUUID1, UUID* pUUID2) {
    if (pUUID1 == NULL || *pUUID1 == NULL) {
        fprintf(stderr, UUID_NULL);
        exit(ERROR);
    }

    if (pUUID2 == NULL || *pUUID2 == NULL) {
        fprintf(stderr, UUID_NULL);
        exit(ERROR);
    }

    BOOL bResult = uuid_compare(*pUUID1, *pUUID2) == 0;
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

char* UUIDToString(UUID* pUUID) {
    if (pUUID == NULL || *pUUID == NULL) {
        fprintf(stderr, UUID_NULL);
        exit(ERROR);
    }

    char* pszResult = (char*) calloc(37, sizeof(char));
    if (pszResult == NULL) {
        fprintf(stderr, "Failed to allocate storage for UUID string.\n");
        exit(ERROR);
    }

    // unparse (to string)
    uuid_unparse(*pUUID, pszResult);

    return pszResult;
}
