# PPLib
A library that implements some of the features of C++ into C.*

## Why?
PPLib ( Panagiotis Petridis Library ) is a mediocare implementation of some of the feature that C++ has in it's STD library. The reason why I wrote it is because I am addicted to the simplicity and beauty of the magnificent C++ language and can't use anything but that. Thus I have to implement alternatives for C in order to write code faster. Hopefully I will be also able to use this library for my course at University. 

## How to use the library
Setting up the library is dead simple ( on linux anyways ). Basically all you do is clone this repository and then run

```
sudo make
sudo make install
```

To use the library after installing it just use the ```-lPPLib``` flag. Example:
```
gcc -Wall main.c -o example.out -lPPLib
```

Simple. Also note that the library is C89 Compliant ( won't give errors/warnings with -ansi flag ).

## Running unit tests
If you want to build and run the tests here is the normal procedure:
```
make build_all_tests
make run_all_tests
# if no errors come up it means things are fine ( most likely that is... )
make clean_all_tests
```
Any commits made that add more tests for the project are most welcome. 

## How to stop using the library
If you happen to be a peasant and want to use raw C ( may God help you ) feel free to uninstall the library simply by running:
```sudo make uninstall``` in the folder where the makefile is.



*Note: This isn't a serious project. It is mostly for personal use. You can use it if you want but take everything with a grain of sault.

Cheers
