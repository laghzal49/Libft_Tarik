#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

void	print_list(t_list *lst)
{
    while (lst)
    {
        printf("%s -> ", (char *)lst->content);
        lst = lst->next;
    }
    printf("NULL\n");
}

void	test_list(void)
{
    t_list *a = ft_lstnew(ft_strdup("one"));
    t_list *b = ft_lstnew(ft_strdup("two"));
    t_list *c = ft_lstnew(ft_strdup("three"));
    ft_lstadd_front(&a, b);
    ft_lstadd_front(&a, c);
    printf("List size: %d\n", ft_lstsize(a));
    printf("Last: %s\n", (char *)ft_lstlast(a)->content);

    // Properly free the list
    t_list *tmp;
    while (a)
    {
        tmp = a->next;
        ft_lstdelone(a, free);
        a = tmp;
    }
}

char	increment_char(unsigned int i, char c)
{
    (void)i;
    return (c + 1);
}

void	increment_char_ptr(unsigned int i, char *c)
{
    (void)i;
    *c += 1;
}

int	main(void)
{
    // Character checks
    printf("ft_isalpha('a'): %d\n", ft_isalpha('a'));
    printf("ft_isdigit('5'): %d\n", ft_isdigit('5'));
    printf("ft_isalnum('A'): %d\n", ft_isalnum('A'));
    printf("ft_isascii(127): %d\n", ft_isascii(127));
    printf("ft_isprint(' '): %d\n", ft_isprint(' '));
    printf("ft_tolower('A'): %c\n", ft_tolower('A'));
    printf("ft_toupper('a'): %c\n", ft_toupper('a'));

    // String functions
    printf("ft_strlen(\"hello\"): %zu\n", ft_strlen("hello"));
    char *dup = ft_strdup("dup");
    printf("ft_strdup: %s\n", dup);
    free(dup);
    printf("ft_strchr(\"abc\", 'b'): %s\n", ft_strchr("abc", 'b'));
    printf("ft_strrchr(\"abcb\", 'b'): %s\n", ft_strrchr("abcb", 'b'));
    printf("ft_strncmp(\"abc\", \"abd\", 2): %d\n", ft_strncmp("abc", "abd", 2));
    char dst[20] = "hi";
    printf("ft_strlcpy: %zu\n", ft_strlcpy(dst, "hello", 20));
    printf("ft_strlcat: %zu\n", ft_strlcat(dst, " world", 20));
    printf("dst after strlcat: %s\n", dst);
    printf("ft_strnstr(\"foo bar\", \"bar\", 7): %s\n", ft_strnstr("foo bar", "bar", 7));
    char *join = ft_strjoin("foo", "bar");
    printf("ft_strjoin: %s\n", join);
    free(join);
    char *trim = ft_strtrim("  hello  ", " ");
    printf("ft_strtrim: '%s'\n", trim);
    free(trim);
    char *substr = ft_substr("abcdef", 2, 3);
    printf("ft_substr: %s\n", substr);
    free(substr);
    char **split = ft_split("a b c", ' ');
    for (int i = 0; split && split[i]; i++)
    {
        printf("ft_split[%d]: %s\n", i, split[i]);
        free(split[i]);
    }
    free(split);
    char *itoa = ft_itoa(-42);
    printf("ft_itoa(-42): %s\n", itoa);
    free(itoa);
    char *mapi = ft_strmapi("abc", increment_char);
    printf("ft_strmapi: %s\n", mapi);
    free(mapi);
    char striteri[] = "abc";
    ft_striteri(striteri, increment_char_ptr);
    printf("ft_striteri: %s\n", striteri);

    // Memory functions
    char mem1[5] = "abcd";
    ft_bzero(mem1, 2);
    printf("ft_bzero: %d %d %c %c\n", mem1[0], mem1[1], mem1[2], mem1[3]);
    char mem2[5] = "abcd";
    ft_memset(mem2, 'x', 3);
    printf("ft_memset: %s\n", mem2);
    char mem3[5];
    ft_memcpy(mem3, "1234", 5);
    printf("ft_memcpy: %s\n", mem3);
    char mem4[5] = "abcd";
    ft_memmove(mem4 + 1, mem4, 4);
    printf("ft_memmove: %s\n", mem4);
    printf("ft_memchr(\"abcde\", 'c', 5): %s\n", (char *)ft_memchr("abcde", 'c', 5));
    printf("ft_memcmp(\"abc\", \"abd\", 3): %d\n", ft_memcmp("abc", "abd", 3));
    int *cal = ft_calloc(5, sizeof(int));
    printf("ft_calloc: %d %d %d %d %d\n", cal[0], cal[1], cal[2], cal[3], cal[4]);
    free(cal);

    // Conversion
    printf("ft_atoi(\"  -42\"): %d\n", ft_atoi("  -42"));

    // File descriptor output
    int fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    ft_putchar_fd('A', fd);
    ft_putstr_fd("BC", fd);
    ft_putendl_fd("DE", fd);
    ft_putnbr_fd(123, fd);
    close(fd);

    // Linked list functions
    test_list();

    return (0);
}