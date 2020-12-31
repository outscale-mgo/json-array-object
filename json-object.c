#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "json-helper.h"

int main(int ac, char **av)
{
	int i = 0;

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
	fflush(stdout);
	return 0;
}
