GCC = cc
LD = ld
LIB = vigenere.c
MAIN = main.c
LIB_DIR = /usr/lib64/
RES_DIR = /usr/include/
BIN_DIR = /usr/bin/

build:
	${GCC} -fPIC -I./ ${LIB} -c -o vigenere.o
	${LD} -shared vigenere.o -o libvigenere.so 
	${GCC} -I./ libvigenere.so ${MAIN} -o vigenere

#all:
#	@echo "Nothing to build"
#
install:
	cp vigenere.h ${RES_DIR};
	cp libvigenere.so ${LIB_DIR};
	cp vigenere ${BIN_DIR}
#	@echo "Can be not install this file"
clear:
	@echo Cleaning...
	rm *.o
	rm vigenere
	rm libvigenere.so
