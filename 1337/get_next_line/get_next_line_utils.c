#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	slen;

	slen = ft_strlen(s);
	if (start >= slen)
	{
		ptr = (char *)malloc(1);
		if (!ptr)
			return (NULL);
		ptr[0] = '\0';
		return (ptr);
	}
	if (len > slen - start)
		len = slen - start;
	ptr = malloc(sizeof(char) * (len+ 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	i;
	size_t	j;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2);
	p = malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		p[i] = s2[j];
		i++;
		j++;
	}
	p[i] = '\0';
	return (p);
}
char	*ft_strchr(char const *s, int c);
void	*ft_memcpy(void *dst, void *src, size_t n);