#include "stdio.h"
#include "ctype.h"
#include "string.h"

#define MAX_LENGTH 100

char char_to_hex(const char src) {
    char l = tolower(src);
    if (l >= 'a') return 0xA + l - 'a';
    return l - '0';
}

int main() {
    char str[MAX_LENGTH];
    scanf("%s", (char *)&str);

    int len = strlen(str);

    char plain[MAX_LENGTH];

    // printf("=> %s\n", str);

    for(int i = 1; i <= 255; i++) {
        int count = 0;
        int idx = 0;
        bzero(plain, MAX_LENGTH);
        for (int j = 0; j < len; j += 2) {
            char fh = char_to_hex(str[j]);
            char sh = char_to_hex(str[j + 1]);
            unsigned char h = (fh << 4) | sh; 
            ////  printf("[%c%c] %d <=> %d => %d ^ %d = %d\n", str[j], str[j + 1], fh, sh, h, i, h ^ i);
            plain[idx] = h ^ i;
            char low = tolower(plain[idx]);
            if (isalpha(low)) count++;
            idx++;
        }
        float score = (float)count/(len / 2);
        // printf("count=%d\tlen/2=%d\t=>%0.2f\n", count, len / 2, ((float)count / (len / 2)));
        if (score >= 0.75) {
            printf("[%d - %c] %s\n", i, i, plain);
        }
        // printf("----------------------------\n");
    }
    return 0;
}
