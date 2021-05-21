#include "header.h"

char	*ft_get_value(t_mylst *lst, char *key)
{
	while(lst)
	{
		if (strcmp(lst->key, key) == 0)
			return(lst->value);
		lst = lst->next;
	}
	return (NULL);
}

void change_oldpwd(t_bin *bin, char *str)
{
	t_mylst *oldpwd;

	oldpwd = find_lst(bin->export, "OLDPWD");
	if(oldpwd->value)
		free(oldpwd->value);
	oldpwd->value = ft_strdup(str);
	oldpwd = find_lst(bin->envp_lst, "OLDPWD");
	if(oldpwd->value)
		free(oldpwd->value);
	oldpwd->value = ft_strdup(str);
}

int		cd_with_minus(t_bin *bin, char **argv)
{
	int		len;
	char	*str;

	len = ft_strlen(bin->argv[1]);
	str = argv[1];
	if (str[0] == '-')
	{
		if (len > 2 || (len == 2 && str[1] != '-'))
			return(-1);
		if (len == 2 && str[1] == '-')
			return(2);
		return(1);
	}
	return (0);
}

void	ft_cd(t_bin *bin, char **argv)
{
	char *home_path;
	char *temp_old_dir;
	char dir[PATH_MAX];

	temp_old_dir = getcwd(dir, PATH_MAX);
	if (!argv[1])
	{
		home_path = ft_get_value(bin->export, "HOME");
		if (home_path)
		{
			chdir(home_path);
			change_oldpwd(bin, temp_old_dir);
		}
		else
			ft_puts("bash: cd: HOME not set");
		return;	
	}
	if (cd_with_minus(bin, argv) == 1)
	{
		if (chdir(ft_get_value(bin->export, "OLDPWD")) == -1)
			ft_puts("bash: cd: OLDPWD not set");
		else
			change_oldpwd(bin, temp_old_dir);
		return;
	}
	if (cd_with_minus(bin, argv) == 2)
	{
		if (chdir(ft_get_value(bin->export, "HOME")) == -1)
			ft_puts("bash: cd: HOME not set");
		else
			change_oldpwd(bin, temp_old_dir);
		return;
	}
	if (cd_with_minus(bin, argv) == -1)
	{
		ft_putstr("bash: cd:");
		write(1, argv[1], 2);
		ft_puts(": invalid option");
		ft_puts("cd: usage: cd [-L|-P] [dir]");
		return;
	}
	if (chdir(argv[1]) == -1)
	{
		ft_putstr("bash: cd:");
		ft_putstr(argv[1]);
		ft_puts(": No such file or directory");
	}
	else
		change_oldpwd(bin, temp_old_dir);
}