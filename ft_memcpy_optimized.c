/* ************************************************************************** */
/*                                                                            */
/*   ft_memcpy_optimized.c - Ultra-fast memcpy implementation                */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>

void	*ft_memcpy_fast(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				*ld;
	const size_t		*ls;

	if (!dst || !src || n == 0)
		return (dst);
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	
	/* Word-aligned copy for large blocks */
	if (n >= sizeof(size_t) * 4)
	{
		/* Align destination to word boundary */
		while ((uintptr_t)d % sizeof(size_t) && n > 0)
		{
			*d++ = *s++;
			n--;
		}
		
		/* Copy words */
		ld = (size_t *)d;
		ls = (const size_t *)s;
		while (n >= sizeof(size_t))
		{
			*ld++ = *ls++;
			n -= sizeof(size_t);
		}
		
		d = (unsigned char *)ld;
		s = (const unsigned char *)ls;
	}
	
	/* Copy remaining bytes */
	while (n--)
		*d++ = *s++;
		
	return (dst);
}
