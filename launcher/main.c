/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tphung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 15:26:52 by tphung            #+#    #+#             */
/*   Updated: 2021/03/30 15:47:26 by tphung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		main(int argc, char **argv, char **envp)
{
	t_main	arg;

	arg.fd_in = 0;
	arg.fd_out = 1;
	arg.argc = argc;
	arg.argv = argv;
	arg.envp = envp;

	launcher(&arg);
	return (0);
}
