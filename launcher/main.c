/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tphung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 15:26:52 by tphung            #+#    #+#             */
/*   Updated: 2021/04/05 15:09:04 by tphung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		main(int argc, char **argv, char **envp)
{
	t_main	arg;
	char	**des;


	arg.pipe_out = 0;
	arg.pipe_in = 0;
	arg.argc = argc;
	arg.argv = argv;
	arg.envp = envp;
	launcher(&arg);
/*
	arg.pipe_in = 1;
	arg.pipe_out = 1;

	des = malloc(sizeof(char*) * 3);
	des[0] = "cat";
	des[1] = "cat";
	des[2] = NULL;
	arg.argv = des;
	launcher(&arg);

	arg.pipe_in = 1;
	arg.pipe_out = 0;

	des = malloc(sizeof(char*) * 3);
	des[0] = "cat";
	des[1] = "cat";
	des[2] = "-e";
	des[3] = NULL;
	arg.argv = des;
	launcher(&arg);
	return (0);*/
}
