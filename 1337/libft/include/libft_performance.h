/* ************************************************************************** */
/*                                                                            */
/*   libft_performance.h - Performance optimization macros                    */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PERFORMANCE_H
# define LIBFT_PERFORMANCE_H

# include "libft.h"

/* Performance optimization macros */
# define LIKELY(x)    __builtin_expect(!!(x), 1)
# define UNLIKELY(x)  __builtin_expect(!!(x), 0)

/* Fast inline versions for small operations */
# define FT_STRLEN_FAST(s) __builtin_strlen(s)
# define FT_MEMCPY_FAST(d, s, n) __builtin_memcpy(d, s, n)

/* Memory alignment helpers */
# define ALIGN_UP(x, align)    (((x) + (align) - 1) & ~((align) - 1))
# define IS_ALIGNED(ptr, align) (((uintptr_t)(ptr) & ((align) - 1)) == 0)

/* Word size operations */
# define WORD_SIZE sizeof(size_t)
# define WORD_MASK (WORD_SIZE - 1)

/* Branch prediction optimized NULL checks */
/* ************************************************************************** */
/*                                                                            */
/*   libft_performance.h - Performance optimization macros                    */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PERFORMANCE_H
# define LIBFT_PERFORMANCE_H

# include <stddef.h>
# include <stdint.h>

/* Performance optimization macros */
# define LIKELY(x)    __builtin_expect(!!(x), 1)
# define UNLIKELY(x)  __builtin_expect(!!(x), 0)

/* Fast inline versions for small operations */
# define FT_STRLEN_FAST(s) __builtin_strlen(s)
# define FT_MEMCPY_FAST(d, s, n) __builtin_memcpy(d, s, n)

/* Memory alignment helpers */
# define ALIGN_UP(x, align)    (((x) + (align) - 1) & ~((align) - 1))
# define IS_ALIGNED(ptr, align) (((uintptr_t)(ptr) & ((align) - 1)) == 0)

/* Word size operations */
# define WORD_SIZE sizeof(size_t)
# define WORD_MASK (WORD_SIZE - 1)

/* Branch prediction optimized NULL checks */
# define NULL_CHECK_RETURN(ptr, ret) 
	do { if (UNLIKELY(!(ptr))) return (ret); } while(0)

# define NULL_CHECK_RETURN_VOID(ptr) 
	do { if (UNLIKELY(!(ptr))) return; } while(0)

/* Performance counters (debug builds) */
# ifdef LIBFT_DEBUG_PERFORMANCE
extern size_t g_ft_strlen_calls;
extern size_t g_ft_memcpy_calls;
extern size_t g_ft_malloc_calls;

#  define PERF_COUNTER_INC(counter) ((counter)++)
#  define PERF_COUNTER_RESET(counter) ((counter) = 0)
# else
#  define PERF_COUNTER_INC(counter)
#  define PERF_COUNTER_RESET(counter)
# endif

/* Function attributes for optimization */
# define FT_PURE     __attribute__((pure))
# define FT_CONST    __attribute__((const))
# define FT_INLINE   static inline __attribute__((always_inline))
# define FT_HOT      __attribute__((hot))
# define FT_COLD     __attribute__((cold))

/* Memory prefetching for large operations */
# define PREFETCH_READ(ptr)  __builtin_prefetch((ptr), 0, 3)
# define PREFETCH_WRITE(ptr) __builtin_prefetch((ptr), 1, 3)

#endif

/* Performance counters (debug builds) */
# ifdef LIBFT_DEBUG_PERFORMANCE
extern size_t g_ft_strlen_calls;
extern size_t g_ft_memcpy_calls;
extern size_t g_ft_malloc_calls;

#  define PERF_COUNTER_INC(counter) ((counter)++)
#  define PERF_COUNTER_RESET(counter) ((counter) = 0)
# else
#  define PERF_COUNTER_INC(counter)
#  define PERF_COUNTER_RESET(counter)
# endif

/* Function attributes for optimization */
# define FT_PURE     __attribute__((pure))
# define FT_CONST    __attribute__((const))
# define FT_INLINE   static inline __attribute__((always_inline))
# define FT_HOT      __attribute__((hot))
# define FT_COLD     __attribute__((cold))

/* Memory prefetching for large operations */
# define PREFETCH_READ(ptr)  __builtin_prefetch((ptr), 0, 3)
# define PREFETCH_WRITE(ptr) __builtin_prefetch((ptr), 1, 3)

#endif
