#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fdt.h"

#define MAX_LEN 32767 + 1 // Integer limit (+1 for null terminator)

struct file_contents
{
    char* lines[MAX_LEN];
};

FILE* files[MAX_LEN];
struct file_contents contents[MAX_LEN];

int main(int charc, char** charv)
{
    if (charc < 3)
    {
        printf("Usage: %s <file-one> <file-two...\n", charv[0]);
        return -1;
    }

    for (int i = 1; i < charc; i++)
    {
        FILE* file = fopen(charv[i], "r");
        if (file == NULL)
        {
            close(files, charc);
            printf("Invalid file: %s\n", charv[i]);
            return -1;
        }

        for (int j = 0; j < MAX_LEN; j++)
        {
            if ((j == 0 && files[j] == NULL) || (files[j - 1] != NULL && files[j] == NULL))
            {
                files[j] = file;
                break;
            }
        }
    }

    for (int i = 1; i < charc; i++)
    {
        if (strcmp(charv[i], charv[1]) != 0) break;

        if (i == charc - 1)
        {
            close(files, charc);
            puts("Your files are the same");
            return 0;
        }
    }

    for (int i = 0; i < charc - 1; i++)
    {
        for (int j = 0; feof(files[i]) == 0 && j < MAX_LEN; j++)
        {
            size_t size = MAX_LEN;
            getline(&contents[i].lines[j], &size, files[i]);
        }
    }

    for (int i = 0; i < charc - 1; i++)
    {
        for (int j = 0; contents[i].lines[j] != NULL; j++)
        {
            if (strcmp(contents[i].lines[j], contents[0].lines[j]) != 0)
            {
                close(files, charc);
                puts("Your files are not the same");
                return 0;
            }
        }
    }
    close(files, charc);

    puts("Your files are the same");
    return 0;
}