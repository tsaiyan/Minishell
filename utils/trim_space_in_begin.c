#include "header.h"

void	trim_space_in_begin(char **str, int i, int j, int len)
{
	int		str_len;
	char	*new;

	str_len = ft_strlen_n(str[0], 1);
	while (ft_isspace(str[0][i]) && str[0][i] != 0)
	{
		++i;
		++len;
	}
	if (len == 0)
		return ;
	new = ft_calloc(1, str_len - len + 1);
	if (!new)
		return ;
	i = -1;
	j = 0;
	while (--len > 0)
		++j;
	while (str[0][j])
		new[++i] = str[0][++j];
	free(*str);
	*str = new;
}
