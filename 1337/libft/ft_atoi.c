#include "libft.h"
int	ft_atoi(const char *n)
{
	int	i;
	int	b;
	int	j;
	int	sign;
	
	sign = 1;
	j = 0;
	i = 0;
	while (n[j])
	{

		if (n[j] == ' ' || (n[j] >= '\t' && n[j] <= '\r'))
		{
			j++;
			continue;
		}
		if (n[j] == '-' || n[j] == '+')
		{
			if (n[j] == '-')
				sign *= -1;
			j++;
			continue;
		}
		b = (n[j] - '0') ;
		i =i * 10 + b;
		j++;
	}
	return (i * sign);
}
