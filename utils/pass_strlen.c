#include "header.h"

int		pass_strlen(char *str)
{
	int			len;

	len = 0;
	while (*str)
	{
		if (*str != EMPTY_SPACE && *str != EMPTY_BACK_SLASH && \
		*str !=	EMPTY_S_QUOT && *str != EMPTY_W_QUOT)
			len++;
		str++;
	}
	return (len);
}