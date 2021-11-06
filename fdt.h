#pragma once
#include <stdio.h>

void close(FILE* arr[], const int limit)
{
    for (int i = 0; i < limit; i += 2)
    {
        fclose(arr[i - 1]);
        fclose(arr[i]);
    }
}