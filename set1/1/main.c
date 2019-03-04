#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_LENGTH 100

char* b64chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

uint8_t char_to_hexbyte(const char src) {
    if (src >= '0' && src <= '9') return src - '0';
    if (src >= 'A' && src <= 'F') return src - 'A' + 0xa;
    if (src >= 'a' && src <= 'f') return src - 'a' + 0xa;
    return 0;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: ./main <Hex-Value>\n\n\tHex-Value: Max length %d\n\n", MAX_LENGTH);
        exit(1);
    }
    size_t s = strlen(argv[1]);
    char m[MAX_LENGTH];
    strncpy(m, argv[1], MAX_LENGTH);
    // size_t out_size = ceil((double)s / 3.0) * 2;
    // printf("s: %zu\tout_size: %zu\n", s, out_size);
    for (int i = 0; i < s; i+=3) {
        uint8_t fi = char_to_hexbyte(m[i]);
        uint8_t se = i + 1 <= s ? char_to_hexbyte(m[i+1]) : 0;
        uint8_t th = i + 2 <= s ? char_to_hexbyte(m[i+2]) : 0;

        uint8_t fbi = (fi << 2) | (se >> 2);
        // Use a 0011 mask (0011 => 3) to get rid of the first 2 bits
        // in order to then shift it 4 times to the left and combine it with 
        // the third (t variable) number with a bitwise or
        uint8_t sbi = ((se & 3) << 4) | th;

        char fb = b64chars[fbi];
        char sb = b64chars[sbi];
        if (i + 2 > s) {
            sb = '=';
        }
        //printf("[%d] fi: %d\tse: %d\tth: %d\t\n    fb: %d sb: %d\n", i, fi, se, th, fb, sb);
        printf("%c%c", fb, sb);
    }
    printf("\n");
    return 0;
}
