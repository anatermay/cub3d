# ft_printf

![42 School](https://img.shields.io/badge/School-42%20Málaga-blue)
![Language](https://img.shields.io/badge/Language-C-brightgreen)
![Rank](https://img.shields.io/badge/Rank-01-orange)
![Score](https://img.shields.io/badge/Score-100%2F100-success)

## 📋 Project Overview

`ft_printf` is a reimplementation of the standard C library function `printf()`. This project is part of the 42 Common Core curriculum (Rank 01) and focuses on understanding variadic functions, string formatting, and low-level programming concepts.

## 🎯 Objectives

- Implement a custom `printf` function that mimics the behavior of the original
- Handle multiple format specifiers and conversions
- Manage variadic arguments using `stdarg.h`
- Return the number of characters printed
- Follow 42 School's coding standards (Norminette)

## 🔧 Supported Format Specifiers

The `ft_printf` function supports the following conversions:

| Specifier | Description | Function |
|-----------|-------------|----------|
| `%c` | Character | `ft_printchar()` |
| `%s` | String | `ft_printstr()` |
| `%p` | Pointer address | `ft_printptr()` |
| `%d` | Decimal integer | `ft_printnbr()` |
| `%i` | Integer | `ft_printnbr()` |
| `%u` | Unsigned decimal | `ft_printunsigned()` |
| `%x` | Hexadecimal (lowercase) | `ft_printhexl()` |
| `%X` | Hexadecimal (uppercase) | `ft_printhexu()` |
| `%%` | Literal percent sign | Built-in handling |

## 📁 Project Structure

```
1_ft_printf/
├── ft_printf.c         # Main printf implementation
├── ft_printf.h         # Header file with prototypes
├── ft_printchar.c      # Character printing
├── ft_printstr.c       # String printing
├── ft_printptr.c       # Pointer printing
├── ft_printnbr.c       # Integer printing
├── ft_printunsigned.c  # Unsigned integer printing
├── ft_printhexl.c      # Lowercase hexadecimal
├── ft_printhexu.c      # Uppercase hexadecimal
├── Makefile           # Build configuration
└── README.md          # This file
```

## 🚀 Usage

### Compilation

```bash
# Compile the library
make

# Clean object files
make clean

# Clean everything
make fclean

# Recompile everything
make re
```

### Integration

```c
#include "ft_printf.h"

int main(void)
{
    int count;
    
    count = ft_printf("Hello %s! You are %d years old.\n", "World", 42);
    ft_printf("Characters printed: %d\n", count);
    
    return (0);
}
```

### Compilation with your project

```bash
gcc -Wall -Wextra -Werror your_file.c libftprintf.a -o your_program
```

## 💡 Key Features

- **Variadic Functions**: Handles variable number of arguments using `va_list`
- **Type Safety**: Proper handling of different data types
- **Error Handling**: Robust error management for edge cases
- **Memory Efficient**: No unnecessary memory allocation
- **Norminette Compliant**: Follows 42 School coding standards

## 🧪 Testing

The project handles various edge cases including:
- NULL string pointers
- Zero values
- Negative numbers
- Maximum and minimum integer values
- Pointer to NULL
- Multiple consecutive format specifiers

## 📈 Performance

- **Time Complexity**: O(n) where n is the format string length
- **Space Complexity**: O(1) - constant space usage
- **Return Value**: Number of characters printed (same as original printf)

## 🔗 Links

- **Author**: Ana Ternero
- **GitHub**: [anatermay](https://github.com/anatermay/)
- **42 Profile**: [aternero](https://profile.intra.42.fr/users/aternero)
- **Repository**: [42_malaga_](https://github.com/anatermay/42_malaga_)

## 🏆 Achievement

**Final Score**: 100/100 ✨

---

*This project was completed as part of the 42 School curriculum at 42 Málaga.*
