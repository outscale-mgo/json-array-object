#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "json-helper.h"

int main(int ac, char **av)
{
	int i = 0;

	printf("[");

	for (i = 1; i < ac; ++i) {
		print_val(av[i]);
		if (i + 1 < ac)
			printf(",");
	}
	printf("]");
	fflush(stdout);
	return 0;
}
