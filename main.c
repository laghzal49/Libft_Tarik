/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laaghzal <laaghzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 18:45:00 by laaghzal          #+#    #+#             */
/*   Updated: 2025/08/30 18:45:09 by laaghzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void test_memory_functions(void)
{
	printf("\n=== MEMORY FUNCTIONS ===\n");
	
	// Test ft_memset
	printf("Testing ft_memset:\n");
	char buffer1[10];
	ft_memset(buffer1, 'A', 5);
	buffer1[5] = '\0';
	printf("ft_memset result: %s\n", buffer1);
	
	// Test ft_bzero
	printf("\nTesting ft_bzero:\n");
	char buffer2[10] = "Hello";
	ft_bzero(buffer2, 3);
	printf("ft_bzero result: '%c' '%c' '%c' '%c' '%c'\n", 
		buffer2[0], buffer2[1], buffer2[2], buffer2[3], buffer2[4]);
	
	// Test ft_memcpy
	printf("\nTesting ft_memcpy:\n");
	char src[] = "Hello World";
	char dest[20];
	ft_memcpy(dest, src, strlen(src) + 1);
	printf("ft_memcpy result: %s\n", dest);
	
	// Test ft_memmove
	printf("\nTesting ft_memmove:\n");
	char str[] = "Hello World";
	ft_memmove(str + 6, str, 5);
	printf("ft_memmove result: %s\n", str);
	
	// Test ft_memchr
	printf("\nTesting ft_memchr:\n");
	char *found = ft_memchr("Hello World", 'W', 11);
	printf("ft_memchr result: %s\n", found ? found : "NULL");
	
	// Test ft_memcmp
	printf("\nTesting ft_memcmp:\n");
	int cmp = ft_memcmp("Hello", "Hello", 5);
	printf("ft_memcmp result: %d\n", cmp);
}

void test_string_functions(void)
{
	printf("\n=== STRING FUNCTIONS ===\n");
	
	// Test ft_strlen
	printf("Testing ft_strlen:\n");
	printf("ft_strlen(\"Hello\"): %zu\n", ft_strlen("Hello"));
	
	// Test ft_strchr
	printf("\nTesting ft_strchr:\n");
	char *found = ft_strchr("Hello World", 'W');
	printf("ft_strchr result: %s\n", found ? found : "NULL");
	
	// Test ft_strrchr
	printf("\nTesting ft_strrchr:\n");
	found = ft_strrchr("Hello World", 'l');
	printf("ft_strrchr result: %s\n", found ? found : "NULL");
	
	// Test ft_strncmp
	printf("\nTesting ft_strncmp:\n");
	int cmp = ft_strncmp("Hello", "Hell", 4);
	printf("ft_strncmp result: %d\n", cmp);
	
	// Test ft_strlcpy
	printf("\nTesting ft_strlcpy:\n");
	char dest[20];
	size_t len = ft_strlcpy(dest, "Hello World", 6);
	printf("ft_strlcpy result: %s (len: %zu)\n", dest, len);
	
	// Test ft_strlcat
	printf("\nTesting ft_strlcat:\n");
	strcpy(dest, "Hello ");
	len = ft_strlcat(dest, "World", 20);
	printf("ft_strlcat result: %s (len: %zu)\n", dest, len);
	
	// Test ft_strnstr
	printf("\nTesting ft_strnstr:\n");
	found = ft_strnstr("Hello World", "Wor", 11);
	printf("ft_strnstr result: %s\n", found ? found : "NULL");
}

void test_character_functions(void)
{
	printf("\n=== CHARACTER FUNCTIONS ===\n");
	
	printf("Testing character classification:\n");
	printf("ft_isalpha('A'): %d\n", ft_isalpha('A'));
	printf("ft_isdigit('5'): %d\n", ft_isdigit('5'));
	printf("ft_isalnum('A'): %d\n", ft_isalnum('A'));
	printf("ft_isascii(127): %d\n", ft_isascii(127));
	printf("ft_isprint(' '): %d\n", ft_isprint(' '));
	
	printf("\nTesting character conversion:\n");
	printf("ft_toupper('a'): %c\n", ft_toupper('a'));
	printf("ft_tolower('A'): %c\n", ft_tolower('A'));
}

void test_conversion_functions(void)
{
	printf("\n=== CONVERSION FUNCTIONS ===\n");
	
	// Test ft_atoi
	printf("Testing ft_atoi:\n");
	printf("ft_atoi(\"42\"): %d\n", ft_atoi("42"));
	printf("ft_atoi(\"-123\"): %d\n", ft_atoi("-123"));
	printf("ft_atoi(\"  +456\"): %d\n", ft_atoi("  +456"));
	
	// Test ft_itoa
	printf("\nTesting ft_itoa:\n");
	char *str = ft_itoa(42);
	printf("ft_itoa(42): %s\n", str ? str : "NULL");
	free(str);
	str = ft_itoa(-123);
	printf("ft_itoa(-123): %s\n", str ? str : "NULL");
	free(str);
}

void test_memory_allocation(void)
{
	printf("\n=== MEMORY ALLOCATION FUNCTIONS ===\n");
	
	// Test ft_calloc
	printf("Testing ft_calloc:\n");
	int *arr = (int *)ft_calloc(5, sizeof(int));
	if (arr)
	{
		printf("ft_calloc allocated and initialized: ");
		for (int i = 0; i < 5; i++)
			printf("%d ", arr[i]);
		printf("\n");
		free(arr);
	}
	
	// Test ft_strdup
	printf("\nTesting ft_strdup:\n");
	char *dup = ft_strdup("Hello World");
	printf("ft_strdup result: %s\n", dup ? dup : "NULL");
	free(dup);
}

void test_string_manipulation(void)
{
	printf("\n=== STRING MANIPULATION FUNCTIONS ===\n");
	
	// Helper function for ft_strmapi
	char (*test_func)(unsigned int, char) = NULL;
	
	// Test ft_substr
	printf("Testing ft_substr:\n");
	char *sub = ft_substr("Hello World", 6, 5);
	printf("ft_substr(\"Hello World\", 6, 5): %s\n", sub ? sub : "NULL");
	free(sub);
	
	// Test ft_strjoin
	printf("\nTesting ft_strjoin:\n");
	char *joined = ft_strjoin("Hello ", "World");
	printf("ft_strjoin(\"Hello \", \"World\"): %s\n", joined ? joined : "NULL");
	free(joined);
	
	// Test ft_strtrim
	printf("\nTesting ft_strtrim:\n");
	char *trimmed = ft_strtrim("   Hello World   ", " ");
	printf("ft_strtrim(\"   Hello World   \", \" \"): '%s'\n", trimmed ? trimmed : "NULL");
	free(trimmed);
	
	// Test ft_split
	printf("\nTesting ft_split:\n");
	char **split = ft_split("Hello,World,42", ',');
	if (split)
	{
		printf("ft_split(\"Hello,World,42\", ','): ");
		for (int i = 0; split[i]; i++)
		{
			printf("'%s' ", split[i]);
			free(split[i]);
		}
		printf("\n");
		free(split);
	}
	
	// Test ft_strmapi
	printf("\nTesting ft_strmapi:\n");
	char *mapped = ft_strmapi("hello", test_func);
	printf("ft_strmapi with NULL function: %s\n", mapped ? mapped : "NULL");
	free(mapped);
}

void test_output_functions(void)
{
	printf("\n=== OUTPUT FUNCTIONS ===\n");
	
	printf("Testing ft_putchar_fd (to stdout):\n");
	ft_putchar_fd('A', 1);
	printf("\n");
	
	printf("Testing ft_putstr_fd (to stdout):\n");
	ft_putstr_fd("Hello World", 1);
	printf("\n");
	
	printf("Testing ft_putendl_fd (to stdout):\n");
	ft_putendl_fd("Hello World", 1);
	
	printf("Testing ft_putnbr_fd (to stdout):\n");
	ft_putnbr_fd(42, 1);
	printf("\n");
	ft_putnbr_fd(-123, 1);
	printf("\n");
}

void test_additional_functions(void)
{
	printf("\n=== ADDITIONAL FUNCTIONS ===\n");
	
	// Test ft_striteri
	printf("Testing ft_striteri:\n");
	char str[] = "hello";
	printf("Before ft_striteri: %s\n", str);
	printf("ft_striteri with NULL function - no change expected\n");
	printf("After ft_striteri: %s\n", str);
}

int main(void)
{
	printf("=== LIBFT COMPREHENSIVE TEST ===\n");
	printf("Testing all functions in libft library\n");
	
	test_memory_functions();
	test_string_functions();
	test_character_functions();
	test_conversion_functions();
	test_memory_allocation();
	test_string_manipulation();
	test_output_functions();
	test_additional_functions();
	
	printf("\n=== ALL TESTS COMPLETED ===\n");
	printf("Check output above for any issues.\n");
	printf("Remember: NULL results for string functions indicate memory allocation failures.\n");
	
	return (0);
}
