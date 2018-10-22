/*
 * @author jason
 * @date 10/21/18
 *
 * Header for utility functions
 */

#ifndef _UTILS_H
#define _UTILS_H

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

/*
 * A safe, error-checked malloc wrapper.
 */
void *safe_malloc(uint32_t size);

#endif
