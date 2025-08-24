/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laaghzal <laaghzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 19:26:29 by laaghzal          #+#    #+#             */
/*   Updated: 2025/08/24 19:51:09 by laaghzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#include "libft.h"

extern char	increment_char(unsigned int i, char c);
extern void	increment_char_ptr(unsigned int i, char *c);

// ...moved to main_utils.c...

static void	test_char(void)
{
	printf("ft_isalpha('a'): %d\n", ft_isalpha('a'));
	printf("ft_isdigit('5'): %d\n", ft_isdigit('5'));
	printf("ft_isalnum('A'): %d\n", ft_isalnum('A'));
	printf("ft_isascii(127): %d\n", ft_isascii(127));
	printf("ft_isprint(' '): %d\n", ft_isprint(' '));
	printf("ft_tolower('A'): %c\n", ft_tolower('A'));
	printf("ft_toupper('a'): %c\n", ft_toupper('a'));
}

static void	test_strings1(void)
{
	char	*dup;
	char	dst[20];
	size_t	l1;
	size_t	l2;
	char	*join;
	char	*trim;
	char	*substr;

	printf("ft_strlen(\"hello\"): %zu\n", ft_strlen("hello"));
	dup = ft_strdup("dup");
	printf("ft_strdup: %s\n", dup);
	free(dup);
	printf("ft_strchr(\"abc\", 'b'): %s\n", ft_strchr("abc", 'b'));
	printf("ft_strrchr(\"abcb\", 'b'): %s\n", ft_strrchr("abcb", 'b'));
	printf("ft_strncmp(\"abc\", \"abd\", 2): %d\n", ft_strncmp("abc", "abd", 2));
	l1 = ft_strlcpy(dst, "hello", 20);
	printf("ft_strlcpy: %zu\n", l1);
	l2 = ft_strlcat(dst, " world", 20);
	printf("ft_strlcat: %zu\n", l2);
	printf("dst: %s\n", dst);
	printf("ft_strnstr(\"foo bar\", \"bar\", 7): %s\n",
		ft_strnstr("foo bar", "bar", 7));
	join = ft_strjoin("foo", "bar");
	printf("ft_strjoin: %s\n", join);
	free(join);
	trim = ft_strtrim("  hello  ", " ");
	printf("ft_strtrim: '%s'\n", trim);
	free(trim);
	substr = ft_substr("abcdef", 2, 3);
	printf("ft_substr: %s\n", substr);
	free(substr);
}

static void	test_split(void)
{
	char   **split;
	int    i;

	split = ft_split("a b c", ' ');
	i = 0;
	while (split && split[i])
	{
		 printf("ft_split[%d]: %s\n", i, split[i]);
		 free(split[i]);
		 i++;
	}
	free(split);
}

static void	test_itoa_mapi_iteri(void)
{
	char   *itoa;
	char   *mapi;
	char   striteri[4];

	itoa = ft_itoa(-42);
	printf("ft_itoa(-42): %s\n", itoa);
	free(itoa);
	mapi = ft_strmapi("abc", increment_char);
	printf("ft_strmapi: %s\n", mapi);
	free(mapi);
	striteri[0] = 'a';
	striteri[1] = 'b';
	striteri[2] = 'c';
	striteri[3] = '\0';
	ft_striteri(striteri, increment_char_ptr);
	printf("ft_striteri: %s\n", striteri);
}

static void	test_memory(void)
{
	char	mem1[5];
	char	mem2[5];
	char	mem3[5];
	char	mem4[5];
	int		*cal;

	mem1[0] = 'a'; mem1[1] = 'b'; mem1[2] = 'c'; mem1[3] = 'd'; mem1[4] = '\0';
	mem2[0] = 'a'; mem2[1] = 'b'; mem2[2] = 'c'; mem2[3] = 'd'; mem2[4] = '\0';
	mem4[0] = 'a'; mem4[1] = 'b'; mem4[2] = 'c'; mem4[3] = 'd'; mem4[4] = '\0';
	ft_bzero(mem1, 2);
	printf("ft_bzero: %d %d %c %c\n", mem1[0], mem1[1], mem1[2], mem1[3]);
	ft_memset(mem2, 'x', 3);
	printf("ft_memset: %s\n", mem2);
	ft_memcpy(mem3, "1234", 5);
	printf("ft_memcpy: %s\n", mem3);
	ft_memmove(mem4 + 1, mem4, 4);
	printf("ft_memmove: %s\n", mem4);
	printf("ft_memchr(\"abcde\", 'c', 5): %s\n",
		(char *)ft_memchr("abcde", 'c', 5));
	printf("ft_memcmp(\"abc\", \"abd\", 3): %d\n", ft_memcmp("abc", "abd", 3));
	cal = ft_calloc(5, sizeof(int));
	printf("ft_calloc: %d %d %d %d %d\n", cal[0], cal[1], cal[2], cal[3], cal[4]);
	free(cal);
}

static void	test_conversion(void)
{
	printf("ft_atoi(\"  -42\"): %d\n", ft_atoi("  -42"));
}

static void	test_fd(void)
{
	int	fd;

	fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd >= 0)
	{
		ft_putchar_fd('A', fd);
		ft_putstr_fd("BC", fd);
		ft_putendl_fd("DE", fd);
		ft_putnbr_fd(123, fd);
		close(fd);
	}
}

static void	print_content(void *content)
{
    printf("%s", (char *)content);
}

static void	*map_toupper(void *content)
{
    char	*str;
    int		i;

    str = ft_strdup((char *)content);
    if (!str)
        return (NULL);
    i = 0;
    while (str[i])
    {
        str[i] = ft_toupper(str[i]);
        i++;
    }
    return (str);
}

static void	test_lstclear(void)
{
    t_list	*lst;

    lst = ft_lstnew(ft_strdup("test1"));
    ft_lstadd_back(&lst, ft_lstnew(ft_strdup("test2")));
    printf("ft_lstclear: ");
    ft_lstclear(&lst, free);
    if (!lst)
        printf("List successfully cleared\n");
    else
        printf("List not cleared\n");
}

static void	test_lstiter(void)
{
    t_list	*lst;

    lst = ft_lstnew(ft_strdup("item1 "));
    ft_lstadd_back(&lst, ft_lstnew(ft_strdup("item2 ")));
    ft_lstadd_back(&lst, ft_lstnew(ft_strdup("item3")));
    
    printf("ft_lstiter: ");
    ft_lstiter(lst, print_content);
    printf("\n");
    
    ft_lstclear(&lst, free);
}

static void	test_lstmap(void)
{
    t_list	*lst;
    t_list	*mapped;

    lst = ft_lstnew(ft_strdup("first "));
    ft_lstadd_back(&lst, ft_lstnew(ft_strdup("second ")));
    ft_lstadd_back(&lst, ft_lstnew(ft_strdup("third")));
    
    mapped = ft_lstmap(lst, map_toupper, free);
    
    printf("ft_lstmap: ");
    ft_lstiter(mapped, print_content);
    printf("\n");
    
    ft_lstclear(&lst, free);
    ft_lstclear(&mapped, free);
}

int	main(void)
{
	test_char();
	test_strings1();
	test_split();
	test_itoa_mapi_iteri();
	test_memory();
	test_conversion();
	test_fd();
	// test_list(); // function not defined
	test_lstclear();
	test_lstiter();
	test_lstmap();
	return (0);
}