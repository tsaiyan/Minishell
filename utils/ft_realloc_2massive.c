#include "libft.h"

static char **copy_mass(char **dst, char **src, size_t len, int *i)
{
	size_t 	line_len;

	if (NULL == src)
	{
		*i += 1;
		dst[*i] = ft_calloc(1, len);
		if (dst[*i] == NULL)
			return (NULL);
		return (dst);
	}
	while (src[++(*i)] != NULL)
	{
		line_len = ft_strlen(src[*i]);
		dst[*i] = malloc(line_len);
		if (dst[*i] == NULL)
			return (NULL);
		ft_strlcpy(dst[*i], src[*i], line_len + 1);
	}
	dst[*i] = ft_calloc(1, len);
	if (dst[*i] == NULL)
		return (NULL);
	return (dst);
}

char 		**ft_realloc_2massive(char **mass, char *arg, int len)
{
	int 	i;
	char 	**ret;
	size_t	line_len;

	i = -1;
	if (len == -1)
		len = (int)ft_massive_len(mass);
	ret = malloc(sizeof(char *) * len + 2);
	if (ret == NULL)
		return (NULL);
	line_len = ft_strlen(arg);
	ret = copy_mass(ret, mass, line_len, &i);
	if (NULL == ret)
		return (NULL);
	ft_strlcpy(ret[i], arg, line_len + 1);
	ret[i + 1] = NULL;
	if (mass)
		ft_free_massive(mass);
	return (ret);
}