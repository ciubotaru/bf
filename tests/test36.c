/**
 * File name: tests/test36.c
 * Project name: bitfield, a bit array manipulation library written in C
 * URL: https://github.com/ciubotaru/bitfield
 * Author: Vitalie Ciubotaru <vitalie@ciubotaru.tokyo>
 * License: General Public License, version 3 or later
 * Copyright 2016, 2017, 2020, 2021
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "bitfield.h"
#include "bitfield-internals.h"
#include <endian.h>

/* Testing uint64tobf() */

int main()
{
	uint64_t unit = 1;
	srand((unsigned)time(NULL));
	unsigned int i, j, cmp;	//counters
	unsigned int len = 80;
	char *msg = "Testing uint64tobf()";
	char *status[] = { "[PASS]", "[FAIL]" };
	int retval = 0;
	unsigned int dots = len - strlen(msg) - 6;	/* 6 is the length of pass/fail string */
	printf("%s", msg);
	for (i = 0; i < dots; i++)
		printf(".");
	unsigned int int64s = (len - 1) / 64 + 1;
	uint64_t *input = calloc(1, int64s * sizeof(uint64_t));
	for (i = 0; i < int64s - 1; i++) {
		for (j = 0; j < 64; j++) {
			if (rand() % 2)
				input[i] |= (unit << j);
		}
	}
	for (i = 0; i < len % 64; i++)
		if (rand() % 2)
			input[int64s - 1] |= (unit << i);
	struct bitfield *output = uint64tobf(input, len);
	for (i = 0; i < int64s; i++)
		input[i] = htole64(input[i]);
	for (i = 0; i < BITNSLOTS(len); i++) {
#if STORAGE_UNIT_SIZE == 8
#elif STORAGE_UNIT_SIZE == 16
		output->field[i] = htole16(output->field[i]);
#elif STORAGE_UNIT_SIZE == 32
		output->field[i] = htole32(output->field[i]);
#elif STORAGE_UNIT_SIZE == 64
		output->field[i] = htole64(output->field[i]);
#else
#error Not implemented
#endif
	}
	cmp = memcmp(input, output->field, (len - 1) / CHAR_BIT + 1);
	if (cmp != 0)
		retval = 1;
	bfdel(output);
	free(input);
	printf("%s\n", status[retval]);
	return retval;
}
