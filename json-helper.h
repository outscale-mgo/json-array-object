#ifndef JSON_HELPER_H_
#define JSON_HELPER_H_

void print_val(const char *v)
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
