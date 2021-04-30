#include "header.h"

//проверяет, есть ли поле уже

static void check_already(t_bin *bin, char *str)
{

}

// чет не работает

void free_double_array(char **str)
{
	int i;

	i = 0;
	while(str[i])
		free(str[i++]);
	free(str);
}

// нужно зафришить bin->ar_export

void add_line_to_export(t_bin *bin, char *str)
{
	int i;
	int j;
	char **new_array;

	i = 0;
	j = 0;
	if (bin->ar_export == NULL)
	{
		bin->ar_export = malloc(sizeof(char *) * ((ft_strlen(bin->envp) + 2)));
		while(bin->envp[i])
		{
			bin->ar_export[i]=ft_strdup(bin->envp[i]);
			i++;
		}
		bin->ar_export[i] = ft_strdup(str);
		bin->ar_export[++i] = NULL;
	}
	else
	{
		new_array = malloc(sizeof(char *) * ((ft_strlen(bin->ar_export) + 2)));
		while(bin->ar_export[i])
		{
			new_array[i]=ft_strdup(bin->ar_export[i]);
			i++;
		}
		//free_double_array(bin->ar_export);
		new_array[i] = ft_strdup(str);
		new_array[++i] = NULL;
		bin->ar_export = new_array;
	}
}

// выводит export без аргументов

void ft_print_export(t_bin *bin)
{
	int i;

	i = 0;
	write(1, "\n", 1);
	while(bin->envp[i])
	{
		ft_putstr("declare -x ");
		ft_puts(bin->envp[i]);
		i++;
	}
}

// функция сортировки

void sort_export(t_bin *bin)
{
	char *str1;
	char *str2;
	char *temp;

	int i = 0;
	int flag = 1;
	while (flag)
	{
		flag = 0;
		while(bin->ar_export[i] && bin->ar_export[i + 1])
		{
			str1 = bin->ar_export[i];
			str2 = bin->ar_export[i + 1];
			if (ft_strcmp(str1, str2) > 0)
			{
				bin->ar_export[i] = str2;
				bin ->ar_export[i + 1] = str1;
				flag = 1;
			}
			i++;
		}
		i = 0;
	}

}

// основная функция export

void ft_export(t_bin *bin)
{
	int i;

	i = 1;
	if (bin->argv[1] == 0)
	{
		sort_export(bin);
		ft_print_export(bin);
	}
	else
	{
		while(bin->argv[i])
		{
			add_line_to_export(bin, bin->argv[i]);
			i++;
		}
		i = 0;
		sort_export(bin);
		ft_puts("");
		while(bin->ar_export[i])
		{
			ft_putstr("declare -x ");
			ft_puts(bin->ar_export[i]);
			i++;
		}
	}
}