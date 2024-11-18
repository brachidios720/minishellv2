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
	(void)av;
	if (ac != 1)
		printf(RED"to many argument\n"RESET);
	else
	{
		print_minishell();
		ft_start(envp);
	}
	return (0);
}
