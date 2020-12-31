
all: json-array json-object

json-array: json-array.o
	$(CC) -pedantic -Wall -Wextra json-array.o -o json-array

json-object: json-object.o
	$(CC) -pedantic -Wall -Wextra json-object.o -o json-object

.PHONY: all
