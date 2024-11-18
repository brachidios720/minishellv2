/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redir_&_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spagliar <spagliar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:27:29 by spagliar          #+#    #+#             */
/*   Updated: 2024/11/18 14:19:03 by spagliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static	int	handle_single_input_redir(t_cmd *cmd, t_data *data, t_redir *redir)
{
	int	fd;

	fd = -1;
	if (*redir == INPUT_FILE)
	{
		fd = open(cmd->in_file, O_RDONLY);
		dprintf(2, "in fd; %d\n", fd);
	}
	if (*redir == HEREDOC)
	{
		cmd->delimiter = ft_strdup(cmd->);
		fd = ft_heredoc(cmd, data);	
	}
	return (fd);
}

static  int	handle_single_output_redir(t_cmd *cmd, t_redir *redir)
{
	int	fd;

	fd = -1;
	if (*redir == OUTPUT_FILE)
		fd = open(cmd->out_file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (*redir == APPEND)
		fd = open(cmd->out_file, O_WRONLY | O_CREAT | O_APPEND, 0777);
	return (fd);
}

void handle_redirection_with_fd(t_cmd *cmd, t_data *data, t_redir *redir)
{
	int fd; //stock temporairement les descripteurs de fichiers
	int i; //index pour parcourir les types de redirection

	i = 0;
	fd = -1;

	while (cmd->redir_type[i]) // Parcourt tous les types de redirection
	{
		if (cmd->redir_type[i] == INPUT_FILE || cmd->redir_type[i] == HEREDOC)
		{
			fd = handle_single_input_redir(cmd, data, redir);
			if (fd < 0)
			{
				perror ("error redir input cf hdle redir with fd");
				return ;
			}
			if (*cmd->in_file != -1) // Ferme le fichier précédent si nécessaire
				close(cmd->in_file);
			cmd->in_file = fd; // Met à jour le fichier d'entrée
		}
		else if (cmd->redir_type[i] == OUTPUT_FILE || cmd->redir_type[i] == APPEND)
		{
			fd = handle_single_output_redir(cmd, redir);
			if (fd < 0)
			{
				perror("error redir output cf hdle single output");
				return ;
			}
			if (cmd->out_file != -1) // Ferme le fichier précédent si nécessaire
				close(cmd->out_file);
			cmd->out_file = fd; // Met à jour le fichier de sortie
		}
		else
		{
			fprintf(stderr, "Unknown redirection type: %d\n", cmd->redir_type[i]);
		}
		i++;
	}
}


// void	handle_redirection(t_cmd *cmd, t_data *data)
// {
// 	int	i;

// 	i = 0;
// 	while (cmd->redir_type[i] != -1)
// 	{
// 		if (cmd->redir_type[i] == INPUT_FILE || cmd->redir_type[i] == HEREDOC)
// 		{
// 			cmd->input_fd = handle_single_input_redir(cmd, data, i);
// 			if (cmd->input_fd < 0)
// 			{
// 				perror("input fd error");
// 			}
// 			dprintf(2, "handle_redirectoin input fd == %d\n", cmd->input_fd);
// 		}
// 		else if (cmd->redir_type[i] == OUTPUT_FILE
// 			|| cmd->redir_type[i] == APPEND)
// 		{
// 			//if (cmd->output_fd != -1 && cmd->output_fd != STDOUT_FILENO)
// 			//	close(cmd->output_fd);
// 			cmd->output_fd = handle_single_output_redir(cmd, i);
// 		}
// 		i++;
// 	}
// 	if (cmd->input_fd == -1)
// 	{
// 		cmd->input_fd = dup(STDIN_FILENO);
// 	}
// 	if (cmd->output_fd == -1)
// 	{
// 		cmd->output_fd = dup(STDOUT_FILENO);
// 	}
// }
