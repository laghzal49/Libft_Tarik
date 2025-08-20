#include <stdlib.h>
#include <string.h>

size_t ft_get_len(long long n)
{
    size_t len;

    len = 0;
    if (n <= 0)
    {
	    len = 1;
    }
    else
    {
	    len = 0;
    }
    while (n)
    {
        len++;
        n /= 10;
    }
    return len;
}

char *ft_itoa(int n)
{
	long long	num;
	size_t		len;
	char		*p;
	
	num = n;
	len = ft_get_len(num);	
	p = malloc(len + 1);
	if (!p)
		return NULL;
	p[len] = '\0';
	if (num == 0)
	{
		p[0] = '0';
		return p;
	}
	if (num < 0)
    	{
		p[0] = '-';
		num = -num;
	}
	while (num > 0)
	{
        	p[--len] = (num % 10) + '0';
		num /= 10;
	}
	return (p);
}
