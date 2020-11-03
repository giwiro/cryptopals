#include "stdio.h"
#include "string.h"
#include "assert.h"
#include "stdint.h"

#define MAX_LENGTH 100

inline int assert_check_size(char* a, char* b) {
    int n_a = strnlen(a, MAX_LENGTH);
    int n_b = strnlen(b, MAX_LENGTH);
    assert(n_a  ==  n_b);
    return n_a;
}

int h_distance(char* a, char* b) {
    int c = 0;
    int size = assert_check_size(a, b);
    for(int i = 0; i < size; i++) {
        uint8_t t = (uint8_t)a[i] ^ (uint8_t)b[i];
        for (t; t > 0; t = t >> 1) {
            if (t & 1) c++;
        }
    }
    return c;
}

int main() {
    char a[] = "this is a test";
    char b[] = "wokka wokka!!!";
    printf("diff: %d\n", h_distance(a, b));
    return 0;
}

