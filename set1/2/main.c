#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>

#define MAX_LENGTH 100

char char_to_hex(const char src) {
    if (src >= '0' && src <= '9') return src - '0';
    if (src >= 'A' && src <= 'F') return src - 'A' + 0xA;
    if (src >= 'a' && src <= 'f') return src - 'a' + 0xA;
    return 0;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: ./main <Hex-Value> <Hex-Value-2>\n\n\tHex-Value: Max length %d\n\n", MAX_LENGTH);
        exit(1);
    }
    size_t s = strlen(argv[1]);
    char m1[MAX_LENGTH];
    char m2[MAX_LENGTH];
    strncpy(m1, argv[1], MAX_LENGTH);
    strncpy(m2, argv[2], MAX_LENGTH);
    for (int i = 0; i < s; i++) {
        char x = char_to_hex(m1[i]) ^ char_to_hex(m2[i]);
        printf("%X", x);
    }
    printf("\n");
    return 0;
}
