#include <string.h>
#include <stdio.h>
#include "libft.h"

char *ft_strnstr(const char *word, const char *tofind, size_t len)
{
    size_t i;
    size_t j;
    size_t tofind_len;
    
    if (!tofind[0])
        return (char *)word;
    tofind_len = 0;
    while (tofind[tofind_len])
        tofind_len++;
    
    i = 0;
    while (word[i] && i < len)
    {
        if (i + tofind_len > len)
            break;
            
        j = 0;
        while (j < tofind_len && word[i + j] == tofind[j])
        {
            j++;
        }
        
        if (j == tofind_len)
            return (char *)&word[i];
            
        i++;
    }
    return NULL;
}
