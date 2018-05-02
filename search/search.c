#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int search(int needleLength, char * needle, int haystackLength, char * haystack) {
    int result = 0;
    for (int i = 0; i < haystackLength; i++) {
        int index = 0;
        while (haystack[i] == needle[index]) {
            index++; i++;
            if (index == needleLength) { result = (i - index); }
        }
    }
    return result;
}

int main(int argc, char const *argv[]) {
    if ( argc != 2 ) {
        printf("usage: %s [ input file ]\n", argv[0]);
    } else {
        int position;
        char line[100];

        // open file
        FILE * fp = fopen(argv[1], "r");
        if (fp == NULL) { exit(EXIT_FAILURE); }

        // read needle
        int needleLength = 0;
        if (fgets(line, sizeof(line), fp)!=NULL) {
            char * ptr;
            needleLength = strtol(line, &ptr, 10);
        } else { exit(EXIT_FAILURE); }

        char needle[needleLength];
        if (fgets(line, sizeof(line), fp)!=NULL) {
            strcpy(needle, line);
        } else { exit(EXIT_FAILURE); }

        // read haystack
        int haystackLength;
        char * haystack = NULL;
        if (fgets(line, sizeof(line), fp)!=NULL) {
            haystackLength = strlen(line);
            haystack = malloc(sizeof(line));
            memcpy(haystack, line, sizeof(line));
        } else { exit(EXIT_FAILURE); }

        position = search(needleLength, needle, haystackLength, haystack);
        if (position == 0) { printf("not found\n");
        } else { printf("found at: %d\n", position); }
    }

    return 0;
}
