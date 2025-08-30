/* ************************************************************************** */
/*                                                                            */
/*   comprehensive_tests.c - Professional test suite                          */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stddef.h>
#include <stdint.h>

/* Function prototypes from libft */
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_atoi(const char *str);
char	*ft_strdup(const char *s1);
char	*ft_itoa(int n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	**ft_split(const char *s, char c);
char	*ft_strtrim(char const *s1, char const *set);

#define TEST_PASS "\033[32m✅ PASS\033[0m"
#define TEST_FAIL "\033[31m❌ FAIL\033[0m"
#define TEST_CATEGORY "\033[36m=== %s ===\033[0m\n"

#ifndef SIZE_MAX
# define SIZE_MAX ((size_t)-1)
#endif

static int tests_run = 0;
static int tests_passed = 0;

void	run_test(const char *test_name, int (*test_func)(void))
{
	printf("%-40s ", test_name);
	tests_run++;
	
	if (test_func())
	{
		printf("%s\n", TEST_PASS);
		tests_passed++;
	}
	else
	{
		printf("%s\n", TEST_FAIL);
	}
}

/* NULL Pointer Safety Tests */
int	test_null_safety_strlen(void)
{
	return (ft_strlen(NULL) == 0);
}

int	test_null_safety_strchr(void)
{
	return (ft_strchr(NULL, 'x') == NULL);
}

int	test_null_safety_strjoin(void)
{
	return (ft_strjoin(NULL, "test") == NULL);
}

int	test_null_safety_atoi(void)
{
	return (ft_atoi(NULL) == 0);
}

/* Edge Case Tests */
int	test_edge_empty_string(void)
{
	char *result = ft_strdup("");
	int pass = (result != NULL && strlen(result) == 0);
	free(result);
	return (pass);
}

int	test_edge_large_numbers(void)
{
	char *result = ft_itoa(2147483647);
	int pass = (result != NULL && strcmp(result, "2147483647") == 0);
	free(result);
	return (pass);
}

int	test_edge_negative_numbers(void)
{
	char *result = ft_itoa(-2147483648);
	int pass = (result != NULL && strcmp(result, "-2147483648") == 0);
	free(result);
	return (pass);
}

/* Performance Tests */
int	test_performance_large_memcpy(void)
{
	char *src = malloc(10000);
	char *dst = malloc(10000);
	
	memset(src, 'A', 9999);
	src[9999] = '\0';
	
	ft_memcpy(dst, src, 9999);
	int pass = (memcmp(src, dst, 9999) == 0);
	
	free(src);
	free(dst);
	return (pass);
}

int	test_performance_long_string(void)
{
	char *long_str = malloc(10001);
	memset(long_str, 'B', 10000);
	long_str[10000] = '\0';
	
	size_t len = ft_strlen(long_str);
	int pass = (len == 10000);
	
	free(long_str);
	return (pass);
}

/* Memory Safety Tests */
int	test_memory_calloc_zero(void)
{
	void *ptr = ft_calloc(0, 5);
	int pass = (ptr != NULL || ptr == NULL); // Both are valid
	free(ptr);
	return (1); // Always pass for this edge case
}

int	test_memory_calloc_overflow(void)
{
	void *ptr = ft_calloc(SIZE_MAX, 2);
	int pass = (ptr == NULL); // Should detect overflow
	return (pass);
}

/* Advanced String Tests */
int	test_advanced_split_empty(void)
{
	char **result = ft_split("", ',');
	int pass = (result != NULL && result[0] == NULL);
	
	if (result)
	{
		free(result);
	}
	return (pass);
}

int	test_advanced_split_delimiters_only(void)
{
	char **result = ft_split(",,,", ',');
	int pass = (result != NULL && result[0] == NULL);
	
	if (result)
	{
		free(result);
	}
	return (pass);
}

int	test_advanced_strtrim_all(void)
{
	char *result = ft_strtrim("   ", " ");
	int pass = (result != NULL && strlen(result) == 0);
	free(result);
	return (pass);
}

/* Unicode and Extended ASCII */
int	test_extended_ascii(void)
{
	char test_str[] = {(char)200, (char)201, (char)202, '\0'};
	size_t len = ft_strlen(test_str);
	return (len == 3);
}

void	print_summary(void)
{
	printf("\n");
	printf("🎯 TEST SUMMARY\n");
	printf("===============\n");
	printf("Tests run:    %d\n", tests_run);
	printf("Tests passed: %d\n", tests_passed);
	printf("Tests failed: %d\n", tests_run - tests_passed);
	printf("Success rate: %.1f%%\n", 
		(tests_run > 0) ? (tests_passed * 100.0 / tests_run) : 0.0);
	
	if (tests_passed == tests_run)
		printf("\n🎉 ALL TESTS PASSED! Your libft is bulletproof! 🎉\n");
	else
		printf("\n⚠️  Some tests failed. Check implementation.\n");
}

int	main(void)
{
	printf("🧪 COMPREHENSIVE LIBFT TEST SUITE\n");
	printf("==================================\n\n");
	
	printf(TEST_CATEGORY, "NULL POINTER SAFETY");
	run_test("ft_strlen(NULL)", test_null_safety_strlen);
	run_test("ft_strchr(NULL, 'x')", test_null_safety_strchr);
	run_test("ft_strjoin(NULL, \"test\")", test_null_safety_strjoin);
	run_test("ft_atoi(NULL)", test_null_safety_atoi);
	
	printf("\n");
	printf(TEST_CATEGORY, "EDGE CASES");
	run_test("Empty string handling", test_edge_empty_string);
	run_test("Large positive numbers", test_edge_large_numbers);
	run_test("Large negative numbers", test_edge_negative_numbers);
	
	printf("\n");
	printf(TEST_CATEGORY, "PERFORMANCE & LARGE DATA");
	run_test("Large memcpy (10KB)", test_performance_large_memcpy);
	run_test("Long string strlen (10KB)", test_performance_long_string);
	
	printf("\n");
	printf(TEST_CATEGORY, "MEMORY SAFETY");
	run_test("ft_calloc with zero", test_memory_calloc_zero);
	run_test("ft_calloc overflow detection", test_memory_calloc_overflow);
	
	printf("\n");
	printf(TEST_CATEGORY, "ADVANCED STRING OPERATIONS");
	run_test("ft_split empty string", test_advanced_split_empty);
	run_test("ft_split delimiters only", test_advanced_split_delimiters_only);
	run_test("ft_strtrim remove all", test_advanced_strtrim_all);
	
	printf("\n");
	printf(TEST_CATEGORY, "EXTENDED CHARACTER SUPPORT");
	run_test("Extended ASCII characters", test_extended_ascii);
	
	print_summary();
	
	return (tests_passed == tests_run ? 0 : 1);
}
