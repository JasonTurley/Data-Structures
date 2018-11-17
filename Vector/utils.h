/*
 * @author jason
 * @date 10/21/18
 *
 * Header for utility functions
 */
#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

/**
 * A safe, error-checked malloc wrapper.
 */
void *safe_malloc(uint32_t size);

/**
 * A safe, error-checked realloc wrapper.
 */
void *safe_realloc(void *ptr, uint32_t size);
