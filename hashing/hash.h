//
// Created by unsubble on 11/15/24.
//

#ifndef HASH_H
#define HASH_H

#include <limits.h>
#include <stddef.h>

#define HASH_CONSTANT 10007
#define HASH_MODULUS (INT_MAX - 1461)

extern int hash_word(const void* any, size_t size);
extern int hash_big_int(long long _int);
extern int hash_int(int _int);
extern int hash_float(float fp);
extern int hash_double(double fp_double);
extern int hash_bytes(const void* any, size_t size);
extern int hash_char(char ch);
extern int hash_str(const char* str);


#endif //HASH_H
