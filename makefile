CFLAGS=-Wall -ansi -pedantic-errors
CC=gcc
UNIT_TEST_FILES=\
unit_tests/vector_unit_tests.c\
unit_tests/list_unit_tests.c\
unit_tests/tests.c\
unit_tests/tests.h

PPLib: vector.o list.o helpers.o
	$(CC) $(CFLAGS) -shared vector.o list.o helpers.o -o lib/libPPLib.so

vector.o: include/vector.c include/vector.h helpers.o
	$(CC) $(CFLAGS) -fPIC -c include/vector.c

list.o: include/list.c include/list.h helpers.o
	$(CC) $(CFLAGS) -fPIC -c include/list.c

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

build_all_tests: $(UNIT_TEST_FILES)\
	build_vector_tests\
	build_list_tests

run_all_tests:\
	run_vector_tests\
	run_list_tests

clean_all_tests:\
	clean_vector_tests\
	clean_list_tests

# Vector tests

build_vector_tests: unit_tests/vector_unit_tests.c unit_tests/tests.h unit_tests/tests.c
	$(CC) $(CFLAGS) -o unit_tests/vector_unit_tests unit_tests/vector_unit_tests.c unit_tests/tests.c -lPPLib

run_vector_tests: unit_tests/vector_unit_tests
	./unit_tests/vector_unit_tests

clean_vector_tests:
	rm unit_tests/vector_unit_tests

# List tests

build_list_tests: unit_tests/list_unit_tests.c unit_tests/tests.h unit_tests/tests.c
	$(CC) $(CFLAGS) -o unit_tests/list_unit_tests unit_tests/list_unit_tests.c unit_tests/tests.c -lPPLib

run_list_tests: unit_tests/list_unit_tests
	./unit_tests/list_unit_tests

clean_list_tests:
	rm unit_tests/list_unit_tests