#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"
#include "string.h"

#define MAX_LENGTH 100

char char_to_hex(const char src) {
    char l = tolower(src);
    if (l >= 'a') return 0xA + l - 'a';
    return l - '0';
}

char* verify(char str[], char x) {
    int len = strlen(str);
    char plain[MAX_LENGTH];
    int count = 0;
    int idx = 0;

    bzero(plain, MAX_LENGTH);

    for (int j = 0; j < len; j += 2) {
        char fh = char_to_hex(str[j]);
        char sh = char_to_hex(str[j + 1]);
        unsigned char h = (fh << 4) | sh; 
        plain[idx] = h ^ x;
        char low = tolower(plain[idx]);
        if (isalpha(low) || low == ' ') count++;
        idx++;
    }
    float score = (float)count/(len / 2);
    if (score >= 0.90) {
        char* r = (char*)malloc(len * sizeof(char));
        memcpy(r, plain, len * sizeof(char));
        return r;
    }

    return NULL;
}

int main() {
    char str[MAX_LENGTH];
    
    while(scanf("%s", (char *)&str) != -1) {
        for(int i = 1; i <= 255; i++) {
            char* t = verify(str, (char)i);
            if (t != NULL) {
                printf("=> %s\n", str);
                printf("\t[%d(%c)] %s\n", i, i, t);
                free(t);
            }
        }
        bzero(str, MAX_LENGTH);
    }

    return 0;
}
