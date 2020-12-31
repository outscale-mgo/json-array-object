
all: json-array json-object

json-array:
	$(CC) -pedantic -Wall -Wextra json-array.c -o json-array

json-object:
	$(CC) -pedantic -Wall -Wextra json-object.c -o json-object

.PHONY: all
