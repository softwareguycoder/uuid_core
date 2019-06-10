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

BOOL AreUUIDsEqual(UUID* pUUID1, UUID* pUUID2) {
    if (!IsUUIDValid(pUUID1)) {
        return FALSE;
    }

    if (!IsUUIDValid(pUUID2)) {
        return FALSE;
    }

    /* the two UUID variables passed to this function
     * have the same value if the uuid_compare function
     * returns zero. */
    return uuid_compare(*pUUID1, *pUUID2) == 0;
}

///////////////////////////////////////////////////////////////////////////////
// CopyUUID function

void CopyUUID(UUID* pDestUUID, UUID* pSrcUUID)
{
  if (pDestUUID == NULL) {
    return; // Required parameter
  }

  if (!IsUUIDValid(pSrcUUID)) {
    return; // Required parameter
  }

  uuid_copy(*pDestUUID, *pSrcUUID);
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
    if (pUUID == NULL || *pUUID == NULL) {
        return FALSE; // NULL reference is not a valid UUID
    }

    return !uuid_is_null(*pUUID);
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
    if (!IsUUIDValid(pUUID)) {
        ThrowUUIDNullException();
    }

    char* pszResult = (char*) malloc(UUID_SIZE*sizeof(char));
    if (pszResult == NULL) {
        ThrowUUIDInvalidException(FAILED_ALLOC_UUID_STORAGE);
    }
    memset(pszResult, 0, UUID_SIZE*sizeof(char));

    // unparse (to string)
    uuid_unparse(*pUUID, pszResult);

    return pszResult;
}
