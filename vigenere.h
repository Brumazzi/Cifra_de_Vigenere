#ifndef __VEGENERI__
	#define __VEGENERI__

	#include <string.h>
	#include <malloc.h>

	#define CRIPT	1
	#define DECRIPT	2

	extern unsigned char *vigenere(const char *key, unsigned char action, const char *value);

#endif
