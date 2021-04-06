#include "header.h"

//int del_

static char *paste_all(t_fts *p, char *ret)
{
	int 	i;

	i = -1;
	while (p->rep_str[++i] != 0)
	{
		ret[p->tmp_i] = p->rep_str[i];
		p->tmp_i++;
	}
	while (p->str[p->tmp_j] != 0)
	{
		ret[p->tmp_i++] = p->str[p->tmp_j++];
	}
	return (ret);
}

static int cmp_find(const char *curr_str, const char *find)
{
	int		i;

	i = 0;
	while (find[i] != 0)
	{
		if (find[i] != curr_str[i])
			return (0);
		i++;
	}
	return (1);
}

static char *replace_in_str(char *ret, t_fts *p, int i, int len)
{
	int		j;

	j = -1;
	if (NULL == ret)
		return (NULL);
	while (++j != i)
		ret[j] = p->str[j];
	while (j + *(p->lim1) != len + 1)
	{
		if (cmp_find(p->str + j, p->substr))
		{
			p->tmp_i = j;
			p->tmp_j = j + *(p->lim1);
			*p->i = j;
			return (paste_all(p, ret));
		}
		else
			ret[j] = p->str[j];
		j++;
	}
	return (NULL);
}

static char *find_substr(t_fts *p, int i)
{
	int 	len;
	char	*ret;

	len = ft_strlen(p->str);
	*(p->lim1) = ft_strlen(p->substr);
	*(p->lim2) = ft_strlen(p->rep_str);
	ret = ft_calloc(sizeof(char), len - *(p->lim1) + *(p->lim2) + 1);
	return (replace_in_str(ret, p, i, len));
}

char *find_substr_in_str_and_replace(const char *substr, char *str,
									const char *rep_str, int *i)
{
	t_fts			p;
	int 			lim1;
	int 			lim2;
	char 			*ret;

	if (!substr || !str)
		return (NULL);
	p = (t_fts){substr, str, rep_str, i, &lim1, &lim2, 0, 0};
	ret = find_substr(&p, *i);
	return (ret);
}
// return may be null its okay, error checked
// not checked "find" can be errors
