/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaiyan <tsaiyan@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 20:30:10 by tsaiyan           #+#    #+#             */
/*   Updated: 2021/05/21 20:30:18 by tsaiyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_get_value(t_mylst *lst, char *key)
{
	while (lst)
	{
		if (strcmp(lst->key, key) == 0)
			return (lst->value);
		lst = lst->next;
	}
	return (NULL);
}

int	change_oldpwd(t_bin *bin, char *str)
{
	t_mylst	*oldpwd;

	oldpwd = find_lst(bin->export, "OLDPWD");
	if (oldpwd->value)
		free(oldpwd->value);
	oldpwd->value = ft_strdup(str);
	oldpwd = find_lst(bin->envp_lst, "OLDPWD");
	if (oldpwd->value)
		free(oldpwd->value);
	oldpwd->value = ft_strdup(str);
	return (0);
}

int	cd_with_minus(t_bin *bin, char **argv)
{
	int		len;
	char	*str;

	len = ft_strlen(bin->argv[1]);
	str = argv[1];
	if (str && str[0] == '-')
	{
		if (len > 2 || (len == 2 && str[1] != '-'))
			return (-1);
		if (len == 2 && str[1] == '-')
			return (2);
		return (1);
	}
	return (0);
}

int	cd_outputs(char **argv, int flag)
{
	if (flag == 1)
	{
		ft_putstr("bash: cd:");
		write(1, argv[1], 2);
		ft_puts(": invalid option");
		ft_puts("cd: usage: cd [-L|-P] [dir]");
	}
	if (flag == 2)
	{
		ft_putstr("bash: cd:");
		ft_putstr(argv[1]);
		ft_puts(": No such file or directory");
	}
	return (0);
}
