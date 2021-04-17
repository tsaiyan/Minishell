#ifndef DEFINES_H
# define DEFINES_H

# define COLOR_GREEN "\x1b[32m"
# define COLOR_YELLOW "\x1b[33m"
# define COLOR_BLUE "\x1b[34m"
# define COLOR_RED "\x1b[31m"
# define COLOR_MAGENTA "\x1b[35m"
# define COLOR_CYAN "\x1b[36m"
# define COLOR_RESET "\x1b[0m"

# define DELETE_CURS_BORD "\x1b[0J"

# define STAGE_FIRST 100
# define STAGE_SECOND 101

# define S_QUOT 39
# define W_QUOT 34

# define EMPTY_SPACE -1
# define EMPTY_S_QUOT -2
# define EMPTY_W_QUOT -3
# define EMPTY_BACK_SLASH -4

# define SHIELD_W_QUOT -20
# define SHIELD_S_QUOT -21

// -1 tab, space

# define DEL_DEF -6

# define SYS_ERR_WRITE	1
# define SYS_ERR_READ	2

# define CALLOC_ERR		-100
# define MALLOC_ERR		-101

# define MULTI_LINE_COMMAND -200
# define CANT_ACCESS_ENVP -201
# define SYNTAX_ERROR -202
# define SYNTAX_ERROR_PREPARS -203

# define TERM_ERRORS -250

# define ERROR_UNEXPECTED_SEMICOLON -300
# define ERROR_UNEXPECTED_PIPE -301
# define ERROR_UNEXPECTED_REDIRECT_BACK -302
# define ERROR_UNEXPECTED_REDIRECT_FORWARD -303

#endif
