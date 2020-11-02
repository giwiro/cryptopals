#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MAX_LENGTH 100

int main() {
    char* line = (char*)malloc(MAX_LENGTH * sizeof(char));
    char key[] = "ICE";
    size_t l = 0;
    int idx = 0;

    while(getline(&line, &l, stdin) >= 0) {
        int len = strnlen(line, MAX_LENGTH);

        // printf("=> %s (%d)\n", line, len);

        for (int i = 0; i < len; i++) {
            // printf("[%c(%d)]", line[i], line[i]);
            // printf("[%d] %c -> %x\n", i, line[i], line[i] ^ key[idx]);
            printf("%02x", line[i] ^ key[idx]);
            idx = (idx + 1) % 3;
        }

        printf("\n");

        bzero(line, MAX_LENGTH);
        free(line);
        line = (char*)malloc(MAX_LENGTH * sizeof(char));
    }
    free(line);
    return 0;
}
