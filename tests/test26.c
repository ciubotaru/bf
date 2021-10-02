/**
 * File name: tests/test26.c
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

/* Testing bf2char_ip() and char2bf_ip() */

int main()
{
	srand((unsigned)time(NULL));
	unsigned int i, cmp;	//counter
	unsigned int len = 80;
	char *msg = "Testing bf2char_ip() and char2bf_ip()";
	char *status[] = { "[PASS]", "[FAIL]" };
	int retval = 0;
	unsigned int dots = len - strlen(msg) - 6;	/* 6 is the length of pass/fail string */
	printf("%s", msg);
	for (i = 0; i < dots; i++)
		printf(".");
	struct bitfield *input = bfnew(len);
	for (i = 0; i < len; i++)
		if (rand() % 2)
			BITSET(input, i);
	unsigned int chars = (len - 1) / CHAR_BIT + 1;
	unsigned char *input_char = malloc(chars * sizeof(unsigned char));
	bf2char_ip(input, input_char);
	/* check first function */
	struct bitfield *check = bfclone(input);
	for (i = 0; i < BITNSLOTS(len); i++) {
#if STORAGE_UNIT_SIZE == 8
#elif STORAGE_UNIT_SIZE == 16
		check->field[i] = htole16(check->field[i]);
#elif STORAGE_UNIT_SIZE == 32
		check->field[i] = htole32(check->field[i]);
#elif STORAGE_UNIT_SIZE == 64
		check->field[i] = htole64(check->field[i]);
#else
#error Not implemented
#endif
	}
	unsigned char *check_char = malloc(chars * sizeof(unsigned char));
	memcpy(check_char, check->field, chars);
	cmp = memcmp(input_char, check_char, chars);
	if (cmp != 0) {
		retval = 1;
		goto ret;
	}
	struct bitfield *output = bfnew(len);
	char2bf_ip(input_char, output);
	/* check second function */
	cmp = bfcmp(input, output, NULL);
	if (cmp != 0) {
		retval = 1;
		goto ret;
	}
 ret:
	bfdel(check);
	free(check_char);
	free(input_char);
	bfdel(input);
	bfdel(output);
	printf("%s\n", status[retval]);
	return retval;
}
