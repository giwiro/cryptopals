#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MAX_LENGTH 1000

int main(int argc, char* argv[]) {
    char m[MAX_LENGTH];
    if (argc != 2) {
        printf("Usage: ./main <Hex-Value>\n\n\tHex-Value: Max length %d\n\n", MAX_LENGTH);
        exit(1);
    }
    strncpy(m, argv[1], MAX_LENGTH);
    printf("argv[1] = %s\n", m);
    return 0;
}
