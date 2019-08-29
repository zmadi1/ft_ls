#include "my_flags.h"

int array_counter(char **str)
{
    int i;

    i = 0;
    while (str[i] != NULL)
    {
        i++;
    }
    return (i);
}