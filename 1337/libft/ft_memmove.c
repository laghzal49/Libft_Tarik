#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*b;
	size_t	i;
	
	b = (char *) src;
	d = (char *) dest;
	i = 0;
	if (!dest || !src)
		return (NULL);
	if (d < b)
	{
		while(i < n)
		{
			d[i] = b[i];
			i++;
		}
	}
	i = n;
	if (d > b)
	{
		while (i > 0)
		{
			i--;
			d[i] = b[i];
		}
	}
	return (dest);
}
/*#include <stdio.h>
#include <string.h>

int main()
{
    char src[20] = "zokmosimo";
    //char srd[20] = "zokmosimo";

    //printf("src lawel: %s\n", src);

    char *s = ft_memmove(src + 3, src, 6);
    printf("%s",s);
    //memmove(srd + 3, srd, 6);

    // Print from the start of both buffers
    //printf("ft_memmove: %s\n", src);
    //printf("memmove: %s\n", srd);

    return 0;
}
*/
