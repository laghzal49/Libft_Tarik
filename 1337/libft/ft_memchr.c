#include <string.h>

#include "libft.h"
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	find;

	p = (unsigned char *)s;
	find = (unsigned char)c;
	while (n > 0)
	{
		if (*p == find)

			return ((void *)p);
		p++;
		n--;
	}
	return (NULL);
}
