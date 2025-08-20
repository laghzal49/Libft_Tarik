#include <string.h>
#include "libft.h"
int	ftt_strlen(char const *s)
{
	int	i;
	
	i = 0;
	while(*s)
	{
		s++;
		i++;
	}

	return (i);
}

char *ft_strrchr(const char *s, int c)
{
    char find = (char)c;
    size_t len = ftt_strlen(s);

    while (1)
    {
        if (s[len] == find)
            return (char *)&s[len];
        if (len == 0)
            break;
        len--;
    }
    return NULL;
}
