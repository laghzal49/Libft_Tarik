#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int	i;
	int	len;
	
	len = ft_strlen(s1) + 1;
	ptr = malloc(sizeof(char) * len);
	i = 0;
	if (!ptr)
		return (NULL);
	while(i < len)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);

}
