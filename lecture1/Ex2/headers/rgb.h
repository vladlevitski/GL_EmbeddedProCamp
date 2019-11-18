#ifndef RGB_H
#define RGB_H

#include <stdint.h>

/**
 * Function converts pixel colors from RGB888 to RGB565 format.
 * @param pixel uint32_t number which represents RGB888 pixel color
 */
void convert_to_rgb565(uint32_t *pixel);

#endif // RGB_H
