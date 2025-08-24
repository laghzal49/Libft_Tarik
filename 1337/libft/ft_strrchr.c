#include <string.h>
#include "libft.h"
char *ft_strrchr(const char *s, int c)
{
    char *last = NULL;
    char ch = (char)c;

    while(*s)
    {
        if (*s == ch)
            last = (char *)s;
        s++;
    }
    if (ch == '\0')
        return (char *)s;
    return last;
}

