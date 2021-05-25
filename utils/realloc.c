#include "header.h"

//static char		*ft_copy(char *dest, char *src, char *buf, int n)
//{
//	int		i;
//
//	i = 0;
//	while (src[i] != '\0')
//	{
//		dest[i] = src[i];
//		i++;
//	}
//	while (--n > -1)
//	{
//		dest[i] = *buf;
//		buf++;
//		i++;
//	}
//	dest[i] = '\0';
//	return (dest);
//}

//void *realloc(void *ptr, size_t newsize)

char	*ft_realloc(char *arg, int count)
{
	char	*new;
	int		len;

	len = ft_strlen(arg);
	new = ft_calloc(sizeof(char), count);
	if (!new)
		return (NULL);
	ft_strlcpy(new, arg, count);
	free(arg);
	return (new);
}
