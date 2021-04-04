/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tphung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 15:26:52 by tphung            #+#    #+#             */
/*   Updated: 2021/04/04 17:25:21 by tphung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		main(int argc, char **argv, char **envp)
{
	t_main	arg;
	char	**des;


	arg.pipe_flag = 0;
	arg.argc = argc;
	arg.argv = argv;
	arg.envp = envp;
	launcher(&arg);
/*
	arg.pipe_flag = 2;

	des = malloc(sizeof(char*) * 3);
	des[0] = "cat";
	des[1] = "cat";
	des[2] = "-e";
	des[3] = NULL;
	arg.argv = des;
	launcher(&arg);
*/
	return (0);
}
