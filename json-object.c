/* MIT License */

/* Copyright (c) 2020 outscale- SAS */

/* Permission is hereby granted, free of charge, to any person obtaining a copy */
/* of this software and associated documentation files (the "Software"), to deal */
/* in the Software without restriction, including without limitation the rights */
/* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell */
/* copies of the Software, and to permit persons to whom the Software is */
/* furnished to do so, subject to the following conditions: */

/* The above copyright notice and this permission notice shall be included in all */
/* copies or substantial portions of the Software. */

/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR */
/* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, */
/* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE */
/* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER */
/* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, */
/* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE */
/* SOFTWARE. */

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "json-helper.h"

int main(int ac, char **av)
{
	int i = 0;
	int flag;

	flag = parse_arg(&ac, &av);

	if (!(ac & 1) || ac < 2) {
		fprintf(stderr, "number of arguments are incorect\n");
		return 1;
	}

	printf("{");
	for (i = 1; i < ac; i += 2) {
		printf("\"%s\":", av[i]);

		print_val(av[i+1]);
		if (i + 2 < ac)
			printf(",");
	}
	printf("}");
	if (flag == END_NL)
		printf("\n");
	fflush(stdout);
	return 0;
}
