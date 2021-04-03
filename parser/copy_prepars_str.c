#include "header.h"

static int		pass_strlen(char *str)
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

static char 	*copy_str(char *dst, char *src)
{
	int 		i;

	i = -1;
	while (*src)
	{
		if (*src != EMPTY_SPACE && *src != EMPTY_BACK_SLASH && \
		*src !=	EMPTY_S_QUOT && *src != EMPTY_W_QUOT)
			dst[++i] = *src;
		src++;
	}
	return (dst);
}

char			*copy_new_prepars_str(char *arg)
{
	int 		len;
	char 		*ret;

	len = pass_strlen(arg);
	ret = ft_calloc(sizeof(char), len + 1);
	if (ret == NULL)
		return (NULL);
	return (copy_str(ret, arg));
}
