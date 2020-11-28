#ifndef SWAP_H
#define SWAP_H

#include <stdint.h>

/**
 * Function swap bytes in 16 bit value.
 * @param input The pointer of value for swap
 */
void swap16(uint16_t *input);

/**
 * Function swap bytes in 32 bit value.
 * @param input The pointer of value for swap
 */
void swap32(uint32_t *input);

/**
 * Function swap bytes in 64 bit value.
 * @param input The pointer of value for swap
 */
void swap64(uint64_t *input);

#endif // SWAP_H
