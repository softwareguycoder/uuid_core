// uuid_core.c - Implementations of publicly-exposed library functions
//

#include "stdafx.h"
#include "uuid_core.h"

///////////////////////////////////////////////////////////////////////////////
// Internally-used functions

void ThrowUUIDException(const char* pszMessage) {
    if (!IsNullOrWhiteSpace(pszMessage)) {
        fprintf(stderr, "%s", pszMessage);
    }
    exit(ERROR);
}

void ThrowUUIDNullException() {
    fprintf(stderr, UUID_NULL);
    exit(ERROR);
}

///////////////////////////////////////////////////////////////////////////////
// Externally-exposed functions

///////////////////////////////////////////////////////////////////////////////
// AreEqual function

BOOL AreEqual(UUID* pUUID1, UUID* pUUID2) {
    if (pUUID1 == NULL || *pUUID1 == NULL) {
        return FALSE;
    }

    if (pUUID2 == NULL || *pUUID2 == NULL) {
        return FALSE;
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
        ThrowUUIDNullException();
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
        ThrowUUIDNullException();
    }

    if (pOutputUUID == NULL || *pOutputUUID == NULL) {
        ThrowUUIDNullException();
    }

    uuid_parse(pszUUID, *pOutputUUID);
}

///////////////////////////////////////////////////////////////////////////////
// UUIDToString function

char* UUIDToString(UUID* pUUID) {
    if (pUUID == NULL || *pUUID == NULL) {
        ThrowUUIDNullException();
    }

    char* pszResult = (char*) calloc(37, sizeof(char));
    if (pszResult == NULL) {
        ThrowUUIDException("Failed to allocate storage for UUID string.\n");
    }

    // unparse (to string)
    uuid_unparse(*pUUID, pszResult);

    return pszResult;
}
