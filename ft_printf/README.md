*This project has been created as part of the 42 curriculum by prashres.*

# ft_printf

## Description

`ft_printf` is a partial reimplementation of the C standard library function `printf`. The goal of the project is to understand variadic functions in C and to build a modular, extensible formatted output function from scratch — without using the real `printf`.

The function parses a format string and processes conversion specifiers, dispatching to dedicated handler functions for each supported type. It returns the total number of characters printed, mirroring the behaviour of the original.

**Supported conversions:**

| Specifier | Description |
|-----------|-------------|
| `%c` | Single character |
| `%s` | String |
| `%p` | Pointer address (hexadecimal) |
| `%d` | Signed decimal integer |
| `%i` | Signed decimal integer |
| `%u` | Unsigned decimal integer |
| `%x` | Unsigned hexadecimal (lowercase) |
| `%X` | Unsigned hexadecimal (uppercase) |
| `%%` | Literal percent sign |

---

## Algorithm & Data Structure Choices

### Parsing approach

The format string is iterated character by character. When a `%` is encountered, the next character is read to determine the conversion specifier. All other characters are printed as-is. This linear scan is simple, correct, and O(n) in the length of the format string.

### Dispatch

Each specifier is handled by a dedicated function (e.g. `ft_print_char`, `ft_printstr`, `ft_print_hexa`, etc.). The main function dispatches to the correct one via a series of conditionals. This keeps each handler small, readable, and independently testable.

### Hexadecimal conversion

Decimal-to-hexadecimal conversion is done recursively:

```c
int ft_print_hexa(unsigned long n, char *base)
{
    int count;

    count = 0;
    if (n >= 16)
        count += ft_print_hexa(n / 16, base);
    count += ft_print_char(base[n % 16]);
    return (count);
}
```

The recursion naturally handles digit ordering (most significant first) without needing a buffer or reversal. The `base` string (`"0123456789abcdef"` or `"0123456789ABCDEF"`) selects lowercase or uppercase output. Maximum recursion depth for a 32-bit value is 8 levels — no stack overflow risk.

### Variadic arguments

The C standard `<stdarg.h>` macros (`va_list`, `va_start`, `va_arg`, `va_end`) are used to access the variable argument list. No custom variadic mechanism is implemented.

---

## Instructions

### Compilation

A `Makefile` is provided at the root. To build the library:

```bash
make
```

This produces `libftprintf.a`, a static library.

To clean object files:

```bash
make clean
```

To remove all generated files including the library:

```bash
make fclean
```

To rebuild from scratch:

```bash
make re
```

### Usage

Include the header and link against the library when compiling your project:

```bash
gcc main.c -L. -lftprintf -o my_program
```

In your source file:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s! You are %d years old.\n", "world", 42);
    return (0);
}
```

---

## Resources

- [C `printf` manual — cppreference](https://en.cppreference.com/w/c/io/fprintf)
- [Variadic functions in C — cppreference](https://en.cppreference.com/w/c/variadic)
- [`stdarg.h` reference — GNU libc](https://www.gnu.org/software/libc/manual/html_node/Variadic-Functions.html)
- [42 Docs — ft_printf subject](https://cdn.intra.42.fr/pdf/pdf/960/ft_printf.en.pdf)
- [Build your own printf — tutorial by Javier Valenzani](https://github.com/jnkernels/printf)

### AI usage

AI (Claude by Anthropic) was used during this project for the following purposes:

- **Conceptual Q&A**: Clarifying how variadic arguments work in C.
- **README writing**: This README was drafted with AI assistance based on project requirements.

AI was not used to write the core implementation code.