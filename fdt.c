#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define FDT_VERSION 2.1

char* contents[INT_MAX / 2];

#include "fdt.h"
int main(int charc, char** charv)
{
    if (charc < 3)
    {
        // Run the help command if '-h' is the first/only argument
        if (charc == 2 && strcmp(charv[1], "-h") == 0) help(charv[0]);

        puts("At least two valid files or a command must be passed to the program");
        printf("Usage: %s <file-one> <file-two...\n", charv[0]);
        return -1;
    }

    for (int i = 1; i < charc; i++)
    {
        FILE* file = fopen(charv[i], "r");

        if (file == NULL)
        {
            fclose(file);
            printf("Invalid file: %s\n", charv[i]);
            return -1;
        }
        fclose(file);
    }

    // Compare the filenames and make sure that they're not all the same file
    for (int i = 1; i < charc; i++)
    {
        if (charv[i] != charv[1]) break;
        if (i == charc - 1)
        {
            puts("Your files are the same");
            return 0;
        }
    }

    // Open the first file and put it's lines into the "contents" array to be compared
    FILE* file = fopen(charv[1], "r");
    for (int i = 0; i != (INT_MAX / 2) + 1 && feof(file) == 0; i++)
    {
        size_t size = INT_MAX;
        getline(&contents[i], &size, file);
    }
    fclose(file);

    // Compares the current file's lines to the first file's lines
    for (int i = 2; i < charc; i++)
    {
        char* line;
        FILE* file = fopen(charv[i], "r");

        for (int j = 0; j < sizeof(contents) / sizeof(contents[0]) && feof(file) == 0; j++)
        {
            size_t size = INT_MAX;
            getline(&line, &size, file);

            if (strcmp(line, contents[j]) != 0)
            {
                fclose(file);
                puts("Your files are not the same");

                // getline() malloc()s strings if they're NULL when passed into it, so we're just freeing the allocated memory
                for (int k = 0; k < sizeof(contents) / sizeof(contents[0]) && contents[k] != NULL; k++) free(contents[k]);

                return 0;
            }
        }

        fclose(file);
    }
    puts("Your files are the same");

    for (int k = 0; k < sizeof(contents) / sizeof(contents[0]) && contents[k] != NULL; k++) free(contents[k]);
    return 0;
}
