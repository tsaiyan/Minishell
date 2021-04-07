#include "header.h"

static int	reverse_redirect(char *line, int *i)
{
	int count;

	count = 0;
	while (!ft_isalnum(line[*i]))
	{
		if ()
		*i += 1;
	}


}

static int forward_redirect(char *line, int *i)
{
	int 	count;

	count = 0;

}

int 		valid_redirects(char *line, int *i)
{
	int 	tmp;
	int 	ret;

	tmp = *i;
	if (line[tmp] == '<')
	{
		ret = reverse_redirect(line, &tmp);
		if (ret < 0)
			return (ret);
	}
	if (line[tmp] == '>')
	{
		ret = forward_redirect(line, &tmp);
		if (ret < 0)
			return (ret);
	}
	return (0);
}