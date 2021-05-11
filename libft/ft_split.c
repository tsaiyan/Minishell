#include "libft.h"

char			**free_split(char **mall)
{
	int i;

	i = 0;
	while (mall[i])
	{
		free(mall[i]);
		i++;
	}
	free(mall);
	return (0);
}

static size_t	atoi_strlen(const char *str, char c)
{
	size_t len;

	len = 0;
	if (!str)
		return (0);
	while (*str == c)
		str++;
	while (*str != c && *str++)
		len++;
	return (len);
}

static size_t	wc(char const *str, char c)
{
	size_t count;

	count = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == c)
			str++;
		if (*str != c)
		{
			count++;
			while (*str != c && *str)
				str++;
		}
	}
	return (count);
}

char			**ft_split(char const *src, char c)
{
	char	**mall;
	size_t	i;

	i = 0;
	if (!src)
		return (NULL);
	 mall = (char**)ft_calloc(sizeof(char*), (wc(src, c) + 1));
		if (!src)
		exit(errno);
	while (*src)
	{
		if (*src != c)
		{
			mall[i] = ft_substr((char*)src, 0, atoi_strlen(src, c));
			if (!mall[i])
			{
				free_split(mall);
				exit(errno);
			}
			i++;
			src += atoi_strlen(src, c) - 1;
		}
		src++;
	}
	return (mall);
}