/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaiyan <tsaiyan@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 20:29:53 by tsaiyan           #+#    #+#             */
/*   Updated: 2021/05/21 20:29:55 by tsaiyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	cd_part_2(t_bin *bin, char **argv)
{
	if (cd_with_minus(bin, argv) == 2)
	{
		if (chdir(ft_get_value(bin->export, "HOME")) == -1)
			ft_puts("bash: cd: HOME not set");
		else
			return (change_oldpwd(bin, bin->temp_old_dir));
	}
	if (cd_with_minus(bin, argv) == -1)
		return (cd_outputs(argv, 1));
	if (argv[1] && chdir(argv[1]) == -1)
		cd_outputs(argv, 2);
	else
		change_oldpwd(bin, bin->temp_old_dir);
	return (0);
}

int	ft_cd(t_bin *bin, char **argv)
{
	bin->temp_old_dir = getcwd(bin->dir, PATH_MAX);
	if (!argv[1])
	{
		bin->home_path = ft_get_value(bin->export, "HOME");
		if (bin->home_path)
		{
			chdir(bin->home_path);
			change_oldpwd(bin, bin->temp_old_dir);
		}
		else
			return (ft_puts("bash: cd: HOME not set"));
	}
	if (cd_with_minus(bin, argv) == 1)
	{
		if (chdir(ft_get_value(bin->export, "OLDPWD")) == -1)
			ft_puts("bash: cd: OLDPWD not set");
		else
			return (change_oldpwd(bin, bin->temp_old_dir));
	}
	return (cd_part_2(bin, argv));
}
