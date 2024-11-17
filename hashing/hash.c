//
// Created by unsubble on 11/15/24.
//

#include "hash.h"

#include <stdio.h>
#include <string.h>
#include <stdint.h>

int hash_word(const void* any, size_t size) {
    const unsigned char* bytes = any;
    long long hash = 0;
    while (size >= 8) {
        uint64_t word;
        memcpy(&word, bytes, sizeof(word));
        size -= 8;
        bytes += 8;
        hash ^= word * HASH_CONSTANT;
        hash = (hash << 13) | (hash >> (64 - 13));
    }
    for (size_t i = 0; i < size; ++i) {
        hash ^= bytes[i] * HASH_CONSTANT;
        hash = (hash << 5) | (hash >> (64 - 5));
    }
    return hash % HASH_MODULUS;
}

int hash_big_int(long long _int) {
    return (int)_int ^ _int >> 32;
}

int hash_int(int _int) {
    return _int;
}

int hash_float(float fp) {
    long long bits;
    memcpy(&bits, &fp, sizeof(fp));
    return hash_big_int(bits);
}

int hash_double(double fp_double) {
    long long bits;
    memcpy(&bits, &fp_double, sizeof(fp_double));
    return hash_big_int(bits);
}

int hash_bytes(const void* any, size_t size) {
    if (any == NULL)
        return 0;
    if (size > 8)
        return hash_word(any, size);
    unsigned long long hash = 0;
    const unsigned char* bytes = any;
    for (size_t i = 0; i < size; ++i) {
        hash = hash + HASH_CONSTANT * bytes[i];
        hash ^= bytes[i];
    }
    return hash % HASH_MODULUS;
}

int hash_char(char ch) {
    return hash_bytes(&ch, 1);
}

int hash_str(const char* str) {
    size_t length = strlen(str);
    return hash_bytes(str, length);
}