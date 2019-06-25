// uuid_core_symbols.h - #define'd constants

#ifndef __UUID_CORE_SYMBOLS_H__
#define __UUID_CORE_SYMBOLS_H__

/**
 * @name UUID
 * @brief Typedef of a uuid_t symbol from the libuuid.so library.  Meant to
 * make code more readable.
 */
typedef uuid_t UUID;

/**
 * @name FAILED_ALLOC_UUID_STORAGE
 * @brief Error message that is displayed when we are unable to allocate a
 * buffer to hold the string representation of a UUID value.
 */
#ifndef FAILED_ALLOC_UUID_STORAGE
#define FAILED_ALLOC_UUID_STORAGE \
	"Failed to allocate storage for UUID string.\n"
#endif //FAILED_ALLOC_UUID_STORAGE

/**
 * @name UUID_BLANK
 * @brief Error message that is displayed when the user passes a blank
 * string to the UUIDFromString function.
 */
#ifndef UUID_BLANK
#define UUID_BLANK \
	"Blank string value passed for UUID to be parsed.\n"
#endif //UUID_BLANK

/**
 * @name UUID_SIZE
 * @brief Size of a string buffer that has the space needed to hold the
 * string version of a UUID..
 */
#ifndef UUID_SIZE
#define	UUID_SIZE				37
#endif //UUID_SIZE

#endif /* __UUID_CORE_SYMBOLS_H__ */
