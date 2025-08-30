/* ************************************************************************** */
/*                                                                            */
/*   benchmark.c - Performance testing suite                                  */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/* Function prototypes from libft */
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlen(const char *s);

#define BENCHMARK_ITERATIONS 1000000
#define TEST_SIZE 1024

typedef struct {
	const char	*name;
	double		time_ms;
	double		speedup;
} t_benchmark;

static double	measure_time(void (*func)(void), int iterations)
{
	clock_t	start, end;
	int		i;

	start = clock();
	for (i = 0; i < iterations; i++)
		func();
	end = clock();
	
	return ((double)(end - start) / CLOCKS_PER_SEC * 1000);
}

static char	*test_data;
static char	*dest_buffer;

static void	test_ft_memcpy(void)
{
	ft_memcpy(dest_buffer, test_data, TEST_SIZE);
}

static void	test_system_memcpy(void)
{
	memcpy(dest_buffer, test_data, TEST_SIZE);
}

static void	test_ft_strlen(void)
{
	ft_strlen(test_data);
}

static void	test_system_strlen(void)
{
	strlen(test_data);
}

int	main(void)
{
	t_benchmark	results[10];
	int			i = 0;
	
	/* Setup test data */
	test_data = malloc(TEST_SIZE + 1);
	dest_buffer = malloc(TEST_SIZE + 1);
	memset(test_data, 'A', TEST_SIZE);
	test_data[TEST_SIZE] = '\0';
	
	printf("🚀 LIBFT PERFORMANCE BENCHMARK\n");
	printf("================================\n\n");
	
	/* Benchmark memcpy */
	results[i].name = "ft_memcpy";
	results[i].time_ms = measure_time(test_ft_memcpy, BENCHMARK_ITERATIONS);
	i++;
	
	results[i].name = "system memcpy";
	results[i].time_ms = measure_time(test_system_memcpy, BENCHMARK_ITERATIONS);
	results[i].speedup = results[i-1].time_ms / results[i].time_ms;
	i++;
	
	/* Benchmark strlen */
	results[i].name = "ft_strlen";
	results[i].time_ms = measure_time(test_ft_strlen, BENCHMARK_ITERATIONS);
	i++;
	
	results[i].name = "system strlen";
	results[i].time_ms = measure_time(test_system_strlen, BENCHMARK_ITERATIONS);
	results[i].speedup = results[i-1].time_ms / results[i].time_ms;
	i++;
	
	/* Print results */
	printf("Function        | Time (ms) | vs System\n");
	printf("----------------|-----------|----------\n");
	for (int j = 0; j < i; j++)
	{
		if (j % 2 == 0)
			printf("%-15s | %8.2f  |\n", results[j].name, results[j].time_ms);
		else
			printf("%-15s | %8.2f  | %.2fx %s\n", 
				results[j].name, results[j].time_ms,
				results[j].speedup,
				(results[j].speedup > 1.0) ? "slower" : "faster");
	}
	
	free(test_data);
	free(dest_buffer);
	return (0);
}
