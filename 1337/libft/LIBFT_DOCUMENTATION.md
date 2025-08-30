# LIBFT FUNCTION DOCUMENTATION

## Overview
This document provides a comprehensive explanation of all functions implemented in the libft library for 42 school BY Tarik Laghzal!.

---

## MEMORY FUNCTIONS

### ft_memset
**Prototype:** `void *ft_memset(void *b, int c, size_t len)`
**Purpose:** Fills the first `len` bytes of memory area pointed to by `b` with the constant byte `c`.
**Returns:** Pointer to the memory area `b`.
**Example:** `ft_memset(buffer, 'A', 5)` fills first 5 bytes with 'A'.

### ft_bzero
**Prototype:** `void ft_bzero(void *s, size_t n)`
**Purpose:** Sets the first `n` bytes of the area starting at `s` to zero.
**Returns:** Nothing (void).
**Example:** `ft_bzero(buffer, 10)` sets first 10 bytes to 0.

### ft_memcpy
**Prototype:** `void *ft_memcpy(void *dst, const void *src, size_t n)`
**Purpose:** Copies `n` bytes from memory area `src` to memory area `dst`.
**Returns:** Pointer to `dst`.
**Note:** Areas must not overlap. Use ft_memmove for overlapping areas.
**Example:** `ft_memcpy(dest, src, strlen(src))` copies string from src to dest.

### ft_memmove
**Prototype:** `void *ft_memmove(void *dst, const void *src, size_t len)`
**Purpose:** Copies `len` bytes from `src` to `dst`. Handles overlapping memory areas safely.
**Returns:** Pointer to `dst`.
**Example:** `ft_memmove(str + 2, str, 5)` safely moves overlapping memory.

### ft_memchr
**Prototype:** `void *ft_memchr(const void *s, int c, size_t n)`
**Purpose:** Locates the first occurrence of `c` in the first `n` bytes of `s`.
**Returns:** Pointer to the matching byte, or NULL if not found.
**Example:** `ft_memchr("Hello", 'l', 5)` returns pointer to first 'l'.

### ft_memcmp
**Prototype:** `int ft_memcmp(const void *s1, const void *s2, size_t n)`
**Purpose:** Compares the first `n` bytes of `s1` and `s2`.
**Returns:** 0 if equal, positive if s1 > s2, negative if s1 < s2.
**Example:** `ft_memcmp("abc", "abd", 3)` returns negative value.

---

## STRING FUNCTIONS

### ft_strlen
**Prototype:** `size_t ft_strlen(const char *s)`
**Purpose:** Calculates the length of the string `s`.
**Returns:** Number of characters in the string (excluding null terminator).
**Example:** `ft_strlen("Hello")` returns 5.

### ft_strchr
**Prototype:** `char *ft_strchr(const char *s, int c)`
**Purpose:** Locates the first occurrence of character `c` in string `s`.
**Returns:** Pointer to the first occurrence, or NULL if not found.
**Example:** `ft_strchr("Hello", 'l')` returns pointer to first 'l'.

### ft_strrchr
**Prototype:** `char *ft_strrchr(const char *s, int c)`
**Purpose:** Locates the last occurrence of character `c` in string `s`.
**Returns:** Pointer to the last occurrence, or NULL if not found.
**Example:** `ft_strrchr("Hello", 'l')` returns pointer to last 'l'.

### ft_strncmp
**Prototype:** `int ft_strncmp(const char *s1, const char *s2, size_t n)`
**Purpose:** Compares at most the first `n` characters of `s1` and `s2`.
**Returns:** 0 if equal, positive if s1 > s2, negative if s1 < s2.
**Example:** `ft_strncmp("abc", "abd", 2)` returns 0 (first 2 chars are equal).

### ft_strlcpy
**Prototype:** `size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)`
**Purpose:** Copies string `src` to `dst` with size limitation.
**Returns:** Length of `src`.
**Note:** Always null-terminates (if dstsize > 0).
**Example:** `ft_strlcpy(dest, "Hello", 10)` copies "Hello" to dest.

### ft_strlcat
**Prototype:** `size_t ft_strlcat(char *dst, const char *src, size_t dstsize)`
**Purpose:** Concatenates string `src` to the end of `dst` with size limitation.
**Returns:** Total length of the string it tried to create.
**Note:** Always null-terminates (if dstsize > 0).
**Example:** `ft_strlcat(dest, "World", 20)` appends "World" to dest.

### ft_strnstr
**Prototype:** `char *ft_strnstr(const char *haystack, const char *needle, size_t len)`
**Purpose:** Locates the first occurrence of `needle` in `haystack` within `len` characters.
**Returns:** Pointer to the first occurrence, or NULL if not found.
**Example:** `ft_strnstr("Hello World", "Wor", 11)` finds "Wor" in string.

---

## CHARACTER CLASSIFICATION AND CONVERSION

### ft_isalpha
**Prototype:** `int ft_isalpha(int c)`
**Purpose:** Tests if character is alphabetic (a-z, A-Z).
**Returns:** Non-zero if true, 0 if false.
**Example:** `ft_isalpha('A')` returns non-zero.

### ft_isdigit
**Prototype:** `int ft_isdigit(int c)`
**Purpose:** Tests if character is a digit (0-9).
**Returns:** Non-zero if true, 0 if false.
**Example:** `ft_isdigit('5')` returns non-zero.

### ft_isalnum
**Prototype:** `int ft_isalnum(int c)`
**Purpose:** Tests if character is alphanumeric (letter or digit).
**Returns:** Non-zero if true, 0 if false.
**Example:** `ft_isalnum('A')` and `ft_isalnum('5')` return non-zero.

### ft_isascii
**Prototype:** `int ft_isascii(int c)`
**Purpose:** Tests if character is a 7-bit ASCII character (0-127).
**Returns:** Non-zero if true, 0 if false.
**Example:** `ft_isascii(65)` returns non-zero.

### ft_isprint
**Prototype:** `int ft_isprint(int c)`
**Purpose:** Tests if character is printable (including space).
**Returns:** Non-zero if true, 0 if false.
**Example:** `ft_isprint(' ')` returns non-zero.

### ft_toupper
**Prototype:** `int ft_toupper(int c)`
**Purpose:** Converts lowercase letter to uppercase.
**Returns:** Uppercase equivalent, or original character if not lowercase.
**Example:** `ft_toupper('a')` returns 'A'.

### ft_tolower
**Prototype:** `int ft_tolower(int c)`
**Purpose:** Converts uppercase letter to lowercase.
**Returns:** Lowercase equivalent, or original character if not uppercase.
**Example:** `ft_tolower('A')` returns 'a'.

---

## CONVERSION FUNCTIONS

### ft_atoi
**Prototype:** `int ft_atoi(const char *str)`
**Purpose:** Converts string to integer.
**Returns:** Integer value of the string.
**Note:** Handles whitespace and optional sign (+/-).
**Example:** `ft_atoi("  -123")` returns -123.

### ft_itoa
**Prototype:** `char *ft_itoa(int n)`
**Purpose:** Converts integer to string.
**Returns:** String representation of the integer, or NULL if allocation fails.
**Note:** Allocates memory - must be freed by caller.
**Example:** `ft_itoa(42)` returns "42".

---

## MEMORY ALLOCATION FUNCTIONS

### ft_calloc
**Prototype:** `void *ft_calloc(size_t count, size_t size)`
**Purpose:** Allocates memory for an array and initializes to zero.
**Returns:** Pointer to allocated memory, or NULL if allocation fails.
**Note:** Memory must be freed by caller.
**Example:** `ft_calloc(5, sizeof(int))` allocates array of 5 integers.

### ft_strdup
**Prototype:** `char *ft_strdup(const char *s1)`
**Purpose:** Duplicates a string by allocating memory and copying.
**Returns:** Pointer to duplicated string, or NULL if allocation fails.
**Note:** Allocates memory - must be freed by caller.
**Example:** `ft_strdup("Hello")` returns allocated copy of "Hello".

---

## STRING MANIPULATION FUNCTIONS

### ft_substr
**Prototype:** `char *ft_substr(char const *s, unsigned int start, size_t len)`
**Purpose:** Extracts substring from string `s` starting at index `start` with maximum length `len`.
**Returns:** Substring, or NULL if allocation fails.
**Note:** Allocates memory - must be freed by caller.
**Example:** `ft_substr("Hello World", 6, 5)` returns "World".

### ft_strjoin
**Prototype:** `char *ft_strjoin(char const *s1, char const *s2)`
**Purpose:** Concatenates two strings into a new string.
**Returns:** New string, or NULL if allocation fails.
**Note:** Allocates memory - must be freed by caller.
**Example:** `ft_strjoin("Hello ", "World")` returns "Hello World".

### ft_strtrim
**Prototype:** `char *ft_strtrim(char const *s1, char const *set)`
**Purpose:** Trims characters in `set` from beginning and end of `s1`.
**Returns:** Trimmed string, or NULL if allocation fails.
**Note:** Allocates memory - must be freed by caller.
**Example:** `ft_strtrim("  Hello  ", " ")` returns "Hello".

### ft_split
**Prototype:** `char **ft_split(char const *s, char c)`
**Purpose:** Splits string `s` using character `c` as delimiter.
**Returns:** Array of strings, or NULL if allocation fails.
**Note:** Allocates memory for array and each string - all must be freed by caller.
**Example:** `ft_split("a,b,c", ',')` returns ["a", "b", "c", NULL].

### ft_strmapi
**Prototype:** `char *ft_strmapi(char const *s, char (*f)(unsigned int, char))`
**Purpose:** Applies function `f` to each character of string `s` with its index.
**Returns:** New string with function applied, or NULL if allocation fails.
**Note:** Allocates memory - must be freed by caller.
**Example:** `ft_strmapi("abc", my_func)` applies my_func(0,'a'), my_func(1,'b'), etc.

### ft_striteri
**Prototype:** `void ft_striteri(char *s, void (*f)(unsigned int, char*))`
**Purpose:** Applies function `f` to each character of string `s` with its index.
**Returns:** Nothing (void).
**Note:** Modifies original string in place.
**Example:** `ft_striteri(str, my_func)` applies my_func to each char with index.

---

## OUTPUT FUNCTIONS

### ft_putchar_fd
**Prototype:** `void ft_putchar_fd(char c, int fd)`
**Purpose:** Outputs character `c` to file descriptor `fd`.
**Returns:** Nothing (void).
**Example:** `ft_putchar_fd('A', 1)` writes 'A' to stdout.

### ft_putstr_fd
**Prototype:** `void ft_putstr_fd(char *s, int fd)`
**Purpose:** Outputs string `s` to file descriptor `fd`.
**Returns:** Nothing (void).
**Example:** `ft_putstr_fd("Hello", 1)` writes "Hello" to stdout.

### ft_putendl_fd
**Prototype:** `void ft_putendl_fd(char *s, int fd)`
**Purpose:** Outputs string `s` followed by newline to file descriptor `fd`.
**Returns:** Nothing (void).
**Example:** `ft_putendl_fd("Hello", 1)` writes "Hello\n" to stdout.

### ft_putnbr_fd
**Prototype:** `void ft_putnbr_fd(int n, int fd)`
**Purpose:** Outputs integer `n` to file descriptor `fd`.
**Returns:** Nothing (void).
**Example:** `ft_putnbr_fd(42, 1)` writes "42" to stdout.

---

## COMPILATION AND USAGE

### Compilation
```bash
# Compile library
make

# Compile with your program
gcc -Wall -Wextra -Werror your_program.c -L. -lft

# Compile main test file
gcc -Wall -Wextra -Werror main.c -L. -lft -o test_libft
```

### Usage Example
```c
#include "libft.h"
#include <stdio.h>

int main(void)
{
    char *str = ft_strdup("Hello World");
    char **words = ft_split(str, ' ');
    
    // Use the functions...
    
    // Clean up memory
    for (int i = 0; words[i]; i++)
        free(words[i]);
    free(words);
    free(str);
    
    return (0);
}
```

### Important Notes
- Functions that allocate memory (marked with "Allocates memory") must have their return values freed
- File descriptor 0 = stdin, 1 = stdout, 2 = stderr
- All functions handle NULL parameters gracefully
- String functions expect null-terminated strings
- Memory functions work with raw bytes
