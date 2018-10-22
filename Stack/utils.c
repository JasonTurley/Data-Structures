/*
 * @author jason
 * @date 10/21/18
 *
 * Implementation of utility functions
 */

#include "utils.h"

/*
 * A safe, error-checked malloc wrapper.
 */
void *safe_malloc(uint32_t size)
{
    void *ret = malloc(size);
    if (!ret) {
        fprintf(stderr, "Failed to allocate %d blocks.\nTerminating program...\n", size);
        exit(EXIT_FAILURE);
    }
    return ret;
}
