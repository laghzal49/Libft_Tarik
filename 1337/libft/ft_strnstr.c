/*#include <string.h>

char *ft_strnstr(const char *word,const char *tofind,size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!tofind[0])
		return (char *)word;
	while (word[i] && i < len)
	{
		j = 0;
		while ((i + j) < len && word[i + j] == tofind[j] && tofind[j])
		{
			if (tofind[j + 1] == '\0')
				return (char *)&word[i];
			j++;
		}
		i++;
	}
	return (NULL);
}
#include <stdio.h>
int main()
{
	char *s = "hello world";
	printf("%s\n",ft_strnstr(s,"world",10));
	printf("%s\n",ft_strnstr(s,"",11));
	printf("%s\n",ft_strnstr("abcdef","de",6));
	printf("%s\n",ft_strnstr(s,"world",5));
	return 0;
}
*/
#include <string.h>
#include <stdio.h>

char *ft_strnstr(const char *word,const char *tofind,size_t len)
{
    size_t i;
    size_t j;

    if (!tofind[0])
        return (char *)word;
    i = 0;
    while (word[i] && i < len)
    {
	printf("i = %zu\n", i);
        j = 0;
        while ((i + j) < len && word[i + j] == tofind[j] && tofind[j])
        {
            if (tofind[j + 1] == '\0')
                return (char *)&word[i];
            j++;
        }
        i++;
    }
    return NULL;
}

int main(void)
{
    char *s = "hello world";
    printf("%s\n", ft_strnstr(s,"",11));
    printf("%s\n", ft_strnstr("abcdef","de",6));
    printf("%s\n", ft_strnstr(s,"world",5));
    return 0;
}

