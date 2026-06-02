*This project has been created as part of the 42 curriculum by prashres.*

# libft

## Description

**libft** is the very first project of the 42 core curriculum. The goal is to recode a set of standard C library functions from scratch — without using the originals — and bundle them into a static library (`libft.a`) that can be reused throughout the rest of the cursus.

The project is divided into three parts:

- **Part 1** — Reimplementations of standard libc functions (string manipulation, memory operations, character checks, type conversions).
- **Part 2** — Additional utility functions not found in libc but commonly useful in C projects (substring extraction, string splitting, integer-to-string conversion, output to file descriptors, etc.).
- **Part3** — A set of functions to manipulate singly linked lists using a custom `t_list` structure.

By building this library, you gain a deep understanding of how low-level C functions work under the hood, and you build a personal toolkit that will be used in almost every future 42 project.

---

## Library Overview

### Part 1 — libc reimplementations

| Function | Description |
|---|---|
| `ft_isalpha` | Checks if a character is alphabetic |
| `ft_isdigit` | Checks if a character is a digit |
| `ft_isalnum` | Checks if a character is alphanumeric |
| `ft_isascii` | Checks if a character is in the ASCII table |
| `ft_isprint` | Checks if a character is printable |
| `ft_toupper` | Converts a character to uppercase |
| `ft_tolower` | Converts a character to lowercase |
| `ft_strlen` | Returns the length of a string |
| `ft_strlcpy` | Copies a string with size bound |
| `ft_strlcat` | Concatenates strings with size bound |
| `ft_strchr` | Finds the first occurrence of a character in a string |
| `ft_strrchr` | Finds the last occurrence of a character in a string |
| `ft_strncmp` | Compares two strings up to n characters |
| `ft_strnstr` | Finds a substring within a bounded string |
| `ft_strdup` | Duplicates a string using malloc |
| `ft_atoi` | Converts a string to an integer |
| `ft_memset` | Fills memory with a constant byte |
| `ft_bzero` | Zeroes out a memory area |
| `ft_memcpy` | Copies a memory area |
| `ft_memmove` | Copies a memory area safely (handles overlap) |
| `ft_memchr` | Scans memory for a byte |
| `ft_memcmp` | Compares two memory areas |
| `ft_calloc` | Allocates and zeroes memory |

### Part 2 — Additional functions

| Function | Description |
|---|---|
| `ft_substr` | Extracts a substring from a string |
| `ft_strjoin` | Concatenates two strings into a new one |
| `ft_strtrim` | Trims specified characters from both ends of a string |
| `ft_split` | Splits a string by a delimiter into an array |
| `ft_itoa` | Converts an integer to a string |
| `ft_strmapi` | Applies a function to each character of a string (returns new string) |
| `ft_striteri` | Applies a function to each character of a string (in-place) |
| `ft_putchar_fd` | Outputs a character to a file descriptor |
| `ft_putstr_fd` | Outputs a string to a file descriptor |
| `ft_putendl_fd` | Outputs a string followed by a newline to a file descriptor |
| `ft_putnbr_fd` | Outputs an integer to a file descriptor |

### Linked list functions

Uses the following structure:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

| Function | Description |
|---|---|
| `ft_lstnew` | Creates a new list node |
| `ft_lstadd_front` | Adds a node at the beginning of the list |
| `ft_lstadd_back` | Adds a node at the end of the list |
| `ft_lstsize` | Returns the number of nodes in the list |
| `ft_lstlast` | Returns the last node of the list |
| `ft_lstdelone` | Deletes a single node using a given function |
| `ft_lstclear` | Deletes and frees all nodes in the list |
| `ft_lstiter` | Applies a function to each node's content |
| `ft_lstmap` | Creates a new list by applying a function to each node |

---

## Instructions

### Compilation

Clone the repository and run `make` at the root:

```bash
git clone <your-repo-url>
cd libft
make
```

This produces `libft.a` — the static library.

To compile with the linked list functions:

```bash
make
```

### Using the library in another project

```bash
cc -Wall -Wextra -Werror main.c -L. -lft -o my_program
```

Make sure `libft.h` is accessible (either in the same directory or passed with `-I`).

### Cleaning up

```bash
make clean    # removes object files
make fclean   # removes object files and libft.a
make re       # fclean + all
```

---

## Resources

- The use of AI was done for certain part of this README file 
- AI and other informative videos in youtube were used inorder to understand the more complex explanations of the code used in the function. 
- A big chunk of credit goes to my fellow peers who spent their time and effort to help me understand the project better.