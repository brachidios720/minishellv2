/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spagliar <spagliar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:41:02 by spagliar          #+#    #+#             */
/*   Updated: 2024/11/18 17:49:41 by spagliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"



/*
	ft_exec()
{
	//check that the path is good
	while (cmd->nb > i)
	{
		//open_file();
			//open_infile()
			//open_outfile()
		//when awe have our infd and (oufd) set;
		exec_cmd();
			//pipe
			//if infile no pb
				//fork --> ft_execve()
							//check if builtins and execute else
							//exeve(cmd);
		i++
	}
	exec_last or first
		//same as exec_cmd just no pipe
}
*/









// void execute_command_or_builtin(t_cmd **cmd, t_env **env, t_data *data)
// {
// 	t_cmd *tmp = *cmd;

//     if (is_builtin(tmp->str))  // Si c'est un builtin
//     {
//         if (ft_strncmp(tmp->str, "export", ft_strlen("export")) == 0 || ft_strncmp(tmp->str, "unset", ft_strlen("unset")) == 0 || ft_strncmp(tmp->str, "cd", ft_strlen("cd")) == 0)
//         {
//             //printf("IIIII\n");
//             exec_builtin(tmp, env, data);  // Exécute directement sans fork
//         }
//         else
//         {
//             pid_t pid = fork();
//             if (pid == 0)
//             {
//                 exec_builtin(tmp, env, data);
//                 exit(EXIT_SUCCESS);
//             }
//             else if (pid > 0)
//             {
//                 waitpid(pid, NULL, 0);
//             }
//             else
//             {
//                 perror("Erreur de fork");
//                 exit(EXIT_FAILURE);
//             }
//         }
//     }
//     else
//     {
//         exec_external(tmp, env);  // Exécuter une commande externe via execve
//     }
// }

// void exec_cmd (t_data *data, t_cmd **cmd, t_env **env)
// {
// 	pid_t	pid;
// 	int		status;
// 	t_cmd	*tmp;
// 	int		fd_in;
// 	int		fd_out;
// 	int		i;

// 	tmp = *cmd;
// 	pid = fork();
// 	i = 0;
// 	if (pid < 0)
// 	{
// 		perror("Erreur lors du fork");
// 		exit(EXIT_FAILURE);
// 	}
// 	if (pid == 0)
// 	{
// 		while (tmp->matrice[i])
// 		{
// 			printf("tmp :  %d %s\n", i, tmp->matrice[i]);
// 			i++;
// 		}
// 		fd_in = tmp->input_fd;
// 		if (fd_in == -1)
// 		{
// 			perror("Erreur de redirection d'entrée");
// 			exit(EXIT_FAILURE);
// 		}
// 		if (fd_in != STDIN_FILENO)
// 		{
// 			if (dup2(fd_in, STDIN_FILENO) == -1)
// 			{
// 				perror("Erreur de redirection d'entrée");
// 				exit(EXIT_FAILURE);
// 			}
// 			close(fd_in);
// 		}
// 		fd_out = tmp->output_fd;
// 		if (fd_out == -1)
// 		{
// 			perror("Erreur de redirection de sortie");
// 			exit(EXIT_FAILURE);
// 		}
// 		if (fd_out != STDOUT_FILENO)
// 		{
// 			if (dup2(fd_out, STDOUT_FILENO) == -1)
// 			{
// 				perror("Erreur de redirection de sortie");
// 				exit(EXIT_FAILURE);
// 			}
// 			close(fd_out);
// 		}
// 		execute_command_or_builtin(&tmp, env, data);
// 		exit(EXIT_SUCCESS);
// 	}
// 	else
// 	{
// 		waitpid(pid, &status, 0);
// 		data->last_exit_status = WEXITSTATUS(status);
// 	}
// }
