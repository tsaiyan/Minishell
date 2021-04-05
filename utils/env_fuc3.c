#include "header.h"

//int del_

static char *find_substr(t_fts *p, int i)
{

}

char *find_substr_instr_and_replace(const char *substr, char *str,
									const char *rep_str, int *i)
{
	t_fts			p;
	int 			lim1;
	int 			lim2;
	char 			*ret;

	if (!substr || !str)
		return (NULL);
	p = (t_fts){substr, str, rep_str, i, &lim1, &lim2};
	if (!i)
		ret = find_substr(&p, 0);
	ret = find_substr(&p, *i);
}