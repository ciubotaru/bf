/**
 * File name: tests/test33.c
 * Project name: bitfield, a bit array manipulation library written in C
 * URL: https://github.com/ciubotaru/bitfield
 * Author: Vitalie Ciubotaru <vitalie at ciubotaru dot tk>
 * License: General Public License, version 3 or later
 * Date: September 10, 2016
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "bitfield.h"
#include "bitfield-internals.h"

/* Testing bftouint16() */

int main()
{
	srand((unsigned)time(NULL));
	int i;			//counter
	int len = 80;
	char *msg = "Testing bftouint16()";
	char *failed = "[FAIL]";
	char *passed = "[PASS]";
	int dots = len - strlen(msg) - 6;	/* 6 is the length of pass/fail string */
	printf("%s", msg);
	for (i = 0; i < dots; i++)
		printf(".");
	struct bitfield *input = bfnew(len);
	for (i = 0; i < len; i++)
		if (rand() % 2)
			BITSET(input, i);
	int bitnslots = (len - 1) / 16 + 1;
	uint16_t *input_int = bftouint16(input);
	for (i = 0; i < bitnslots; i++) {
		if (input_int[i] !=
		    (uint16_t)bfsub(input, i * 16,
					(i + 1) * 16)->field[0]) {
			printf("%s\n", failed);
			return 1;
		}
	}
	printf("%s\n", passed);
	return 0;
}
