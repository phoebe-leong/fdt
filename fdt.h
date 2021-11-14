#pragma once
#include <stdlib.h>
#include <stdio.h>

void help(const char* filename)
{
    puts("--HELP--\n");

    printf("FDT Version %.1f\n", FDT_VERSION);
    printf("Maximum length for files: %lu lines\n\n", (sizeof(contents) / sizeof(contents[0])) - 1);
    printf("Usage: %s <file-one> <file-two...\n", filename);

    exit(0);
}
