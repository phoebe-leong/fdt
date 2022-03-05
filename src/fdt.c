#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "fdt.h"

int main(int charc, char** charv)
{
    if (charc == 1 || strcmp(charv[1], "--help") == 0)
    {
        help(charv[0]);
        exit(0);
    }
    else if (strcmp(charv[1], "--version") == 0)
    {
        printf("%s\n", FDT_VERSION);
        exit(0);
    }

    for (int i = 1; i < charc && strcmp(charv[i], charv[1]) == 0; i++)
    {
        if (i == charc - 1)
        {
            puts("Your files are the same!");
            exit(0);
        }
    }

    int f_size = 0;
    FILE* file = fopen(charv[1], "r");

    // Finding the amount of lines that the first file contains
    for (; feof(file) == 0; f_size++)
    {
        char* line;
        size_t size;
        getline(&line, &size, file);
    }
    fclose(file);
    file = fopen(charv[1], "r");

    // Using the line amount to make an array to store the lines
    char* first[f_size + 1];
    for (int i = 0; feof(file) == 0; i++)
    {
        first[i] = fdt_getline(file);
    }
    fclose(file);

    // Iterating through the rest of the parameters and comparing them to the first file
    for (int i = 2; i < charc; i++)
    {
        file = fopen(charv[i], "r");
        for (int j = 0; feof(file) == 0; j++)
        {
            char* line = fdt_getline(file);
            if (strcmp(first[j], line) != 0)
            {
                puts("Your files are not the same!");

                fclose(file);
                exit(0);
            }
        }
        fclose(file);
    }
    puts("Your files are the same!");

    fclose(file);
    exit(0);
}
