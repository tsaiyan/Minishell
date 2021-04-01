#ifndef DEFINES_H
# define DEFINES_H

# define COLOR_GREEN "\x1b[32m"
# define COLOR_YELLOW "\x1b[33m"
# define COLOR_BLUE "\x1b[34m"
# define COLOR_RED "\x1b[31m"
# define COLOR_MAGENTA "\x1b[35m"
# define COLOR_CYAN "\x1b[36m"
# define COLOR_RESET "\x1b[0m"
# define S_QUOT 39
# define W_QUOT 34

# define EMPTY_SPACE -1
# define EMPTY_S_QUOT -2
# define EMPTY_W_QUOT -3
# define EMPTY_BACK_SLASH -4

// -1 tab, space

# define DEL_DEF -6

# define SYS_ERR_WRITE	1
# define SYS_ERR_READ	2

# define CALLOC_ERR		-100
# define MALLOC_ERR		-101

# define MULTI_LINE_COMMAND -200
# define CANT_ACCESS_ENVP -201

#endif
