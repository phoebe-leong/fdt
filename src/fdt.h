#pragma once
#include <stdlib.h>
#include <stdio.h>

#define FDT_VERSION "3.0"

void help(const char* filename)
{
    puts("**--------- HELP ---------**");
    printf("Usage: %s <file-one> <file-two...>\n\n", filename);
    puts("At least two files must be passed as parameters so they can be compared");
}

char* fdt_getline(FILE* file)
{
    char* line;
    size_t size;
    getline(&line, &size, file);

    return line;
}
