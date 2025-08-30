# Libft

[![42 School](https://img.shields.io/badge/42-School-000000?style=flat&logo=42&logoColor=white)](https://42.fr)
[![Norminette](https://img.shields.io/badge/Norminette-Passing-success)](https://github.com/42School/norminette)
[![Made with C](https://img.shields.io/badge/Made%20with-C-blue)](https://en.wikipedia.org/wiki/C_(programming_language))

A comprehensive implementation of the C standard library functions as part of the 42 School curriculum. This project recreates essential libc functions with the `ft_` prefix, providing a solid foundation for future C projects.

## 📋 About

Libft is the first project at 42 School, where students must recreate various functions from the C standard library. This implementation includes all mandatory functions plus bonus linked list operations, following the strict 42 coding standards (Norminette).

## 🛠️ Functions Implemented

### Part 1 - Libc Functions
- **Character checks**: `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`
- **String manipulation**: `ft_strlen`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strlcpy`, `ft_strlcat`
- **Memory operations**: `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`
- **Conversions**: `ft_atoi`, `ft_tolower`, `ft_toupper`
- **Memory allocation**: `ft_calloc`, `ft_strdup`

### Part 2 - Additional Functions
- **String utilities**: `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_itoa`, `ft_strmapi`, `ft_striteri`
- **File descriptor operations**: `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`

### Bonus - Linked List Functions
- **List operations**: `ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`, `ft_lstadd_back`
- **List manipulation**: `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`

## 🚀 Usage

### Compilation

```bash
# Compile the library
make

# Compile with bonus functions
make bonus

# Clean object files
make clean

# Clean everything
make fclean

# Recompile
make re
```

### Integration

```c
#include "libft.h"

int main(void)
{
    char *str = ft_strdup("Hello, 42!");
    char **split = ft_split("one,two,three", ',');
    
    ft_putstr_fd(str, 1);
    // ... use your functions
    
    free(str);
    // Don't forget to free allocated memory!
    return (0);
}
```

## 📁 Project Structure

```
libft/
├── ft_*.c              # Function implementations
├── libft.h             # Header file with prototypes
├── Makefile            # Compilation rules
├── README.md           # This file
└── LICENSE             # License information
```

## ⚡ Key Features

- **Norminette Compliant**: Follows 42 School coding standards
- **Memory Safe**: Proper error handling and memory management
- **Well Documented**: Clear and comprehensive header file
- **Optimized**: Efficient implementations following best practices
- **Bonus Content**: Complete linked list implementation

## 🧪 Testing

The library has been tested with various testers including:
- [Libft Unit Test](https://github.com/alelievr/libft-unit-test)
- [libft-war-machine](https://github.com/y3ll0w42/libft-war-machine)
- [Francinette](https://github.com/xicodomingues/francinette)

## 🎯 42 Project Guidelines

This implementation strictly follows:
- **Norminette**: All files pass norm checks
- **No global variables**: Clean, reentrant code
- **Error handling**: Robust against edge cases
- **Memory management**: No leaks or invalid access

## 📚 Learning Outcomes

Through this project, I gained experience in:
- Low-level C programming
- Memory management and pointer manipulation
- Data structure implementation (linked lists)
- Code organization and documentation
- Following strict coding standards

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 🤝 Contributing

While this is a school project, feedback and suggestions are welcome! Feel free to open an issue if you find any bugs or improvements.

---

*Made with ☕ at 42 School*