#include <string.h>

int	ft_strlen(char const *s)
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
    size_t len = ft_strlen(s);

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
#include <stdio.h>

int main(void)
{
    const char *str = "hello world";
    char *res;

    // Test 1: normal char in middle
    res = ft_strrchr(str, 'o');
    if (res)
        printf("Last 'o' in \"%s\" = \"%s\"\n", str, res);
    else
        printf("Not found\n");

    // Test 2: first char
    res = ft_strrchr(str, 'h');
    if (res)
        printf("Last 'h' in \"%s\" = \"%s\"\n", str, res);
    else
        printf("Not found\n");

    // Test 3: character not in string
    res = ft_strrchr(str, 'z');
    if (res)
        printf("Found 'z': %s\n", res);
    else
        printf("Not found (z)\n");

    // Test 4: null terminator
    res = ft_strrchr(str, '\0');
    if (res)
        printf("Found null terminator at: \"%s\"\n", res);
    else
        printf("Not found (\\0)\n");

    return 0;
}

