CFLAGS=-Wall -ansi -pedantic-errors
CC=gcc

PPLib: vector.o helpers.o
	$(CC) $(CFLAGS) -shared vector.o helpers.o -o lib/libPPLib.so

vector.o: include/vector.c include/vector.h helpers.o
	$(CC) $(CFLAGS) -fPIC -c include/vector.c

helpers.o: include/helpers.c include/helpers.h
	$(CC) $(CFLAGS) -fPIC -c include/helpers.c

clean:
	rm *.o

install:
	sudo rm -rf /usr/include/PPLib
	sudo rm -rf /usr/lib/libPPLib.so
	sudo mkdir -p /usr/include/PPLib
	sudo cp include/* /usr/include/PPLib/
	sudo cp lib/libPPLib.so /usr/lib/

uninstall:
	sudo rm -rf /usr/include/PPLib
	sudo rm -rf /usr/lib/libPPLib.so

# Unit tests

run_vector_tests: unit_tests/vector_unit_tests.c unit_tests/tests.h unit_tests/tests.c
	$(CC) $(CFLAGS) -o unit_tests/vector_unit_tests unit_tests/vector_unit_tests.c unit_tests/tests.c -lPPLib
	./unit_tests/vector_unit_tests
	rm unit_tests/vector_unit_tests