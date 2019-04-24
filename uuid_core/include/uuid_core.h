// uuid_core.h - Defines the public interface to the uuid_core library
//

#ifndef __UUID_CORE_H__
#define __UUID_CORE_H__

#include "uuid_core_symbols.h"

/**
 * @brief Generates a new universally-unique identifier (UUID).
 * @param pUUID Address of a memory location that will receive the value
 * generated.  This must have a valid address value.
 * @remarks You can pass a null value here
 */
void GenerateNewUUID(UUID* pUUID);

/**
 * @brief Determines whether the UUID supplied is NULL or not.
 * @param pUUID Pointer to the UUID value to be checked.
 * @returns TRUE if the uuid variable has a valid value; FALSE otherise.
 */
BOOL IsUUIDValid(UUID* pUUID);

/**
 * @brief Given a string representation of a UUID, produces a data value.
 * @param pszUUID String representation of the UUID.
 * @param pOutputUUID Pointer to a buffer that receives the data value. Must
 * not be NULL.
 * @remarks String should be formatted "1b4e28ba-2fa1-11d2-883f-0016d3cca427\0"
 * or otherwise the output is not deterministic.
 */
void UUIDFromString(const char* pszUUID, UUID* pOutputUUID);

/**
 * @brief Given a UUID value, puts its string representation into a char array.
 * @param uuid UUID value to represent as a string.
 * @return Pointer to the first element of a char* buffer that contains the
 * string representation of the UUID provided.
 * @remarks An example value output is "1b4e28ba-2fa1-11d2-883f-0016d3cca427\0"
 * The output buffer is always 37 bytes long.  The memory whose address is
 * returned by this function must be freed with free().
 */
char* UUIDToString(UUID uuid);

#endif /* __UUID_CORE_H__ */
