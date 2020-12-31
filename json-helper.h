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

#ifndef JSON_HELPER_H_
#define JSON_HELPER_H_

#define END_NL 1


static int parse_arg(int *acp, char ***avp)
{
	char **av = *avp;
	char *a;
	int ret = 0;

	if (*acp < 2)
		return 0;
	a = av[1];

	if (a[0] == '-') {
		const char *ta = &a[1];

		for (; *ta; ++ta) {
			if (*ta == 'l') {
				ret |= END_NL;
			} else {
				fprintf(stderr,
					"bad argument, supported: -l\n");
				exit(1);
			}
		}
		*acp = *acp - 1;
		*avp = *avp + 1;
	}
	return ret;
}

static void print_val(const char *v)
{
	int is_num = 1;
	const char *c = v;

	if (*c == '0')
		++c;
	if (*c == 'x')
		++c;

	for (; *c; ++c) {
		if (!isdigit(*c)) {
			is_num = 0;
			break;
		}
	}

	if (v[0] == '{'  || v[0] == '[' || is_num)
		printf("%s", v);
	else
		printf("\"%s\"", v);
}

#endif
