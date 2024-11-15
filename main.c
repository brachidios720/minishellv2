/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pag <pag@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:35:04 by pag               #+#    #+#             */
/*   Updated: 2024/11/15 18:47:22 by pag              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

void	print_minishell(void)
{
	printf("\033[32m ##   ##    ##                ##\
				  ###                ###      ###        ###    ####\033[0m\n");
	printf("\033[32m ### ###                        \
				  ##                 ##       ##       ####   ##  ##\033[0m\n");
	printf("\033[32m #######   ###     #####     ### \
		 #####    ##       ####      ##       ##      ## ##       ##\033[0m\n");
	printf("\033[32m #######    ##     ##  ##     ## \
		##        #####   ##  ##     ##       ##     ##  ##     ###\033[0m\n");
	printf("\033[32m ## # ##    ##     ##  ##     ## \
		#####    ##  ##  ######     ##       ##     #######   ##\033[0m\n");
	printf("\033[32m ##   ##    ##     ##  ##     ## \
		   ##   ##  ##  ##         ##       ##         ##   ##  ##\033[0m\n");
	printf("\033[32m ##   ##   ####    ##  ##    ####\
	  ######   ###  ##   #####    ####     ####        ##   ######\033[0m\n");
}

int	main(int ac, char **av, char **envp)
{
	t_data	*data;
	t_cmd	*cmd;
	t_env	*env;

	data = NULL;
	cmd = NULL;
	env = NULL;
	(void)ac;
	(void)av;
	if (ac != 1)
		printf(RED"to many argument\n"RESET);
	print_minishell();
	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (1);
	env = init_env(envp);
	init_pwd (&env);
	free (cmd);
	free (data);
	return (0);
}
