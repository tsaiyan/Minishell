#include "header.h"

int     check_array_is_ascii(char *buf)
{
    int i;

    i = -1;    
    while (buf[++i] != 0)
    {
        if (!ft_isascii(buf[i]))
            return (0);
    }
    return (1);
}