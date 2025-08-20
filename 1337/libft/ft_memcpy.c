#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*p;
	char	*s;
	size_t		i;

	p = (char *)dest;
	s = (char *)src;
	if (!src || !dest)
		return (NULL);
	i = 0;
	while (i < n)
	{
		p[i] = s[i];
		i++;
	}
	return (dest);
}
