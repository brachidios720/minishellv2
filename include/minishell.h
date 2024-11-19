/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:12:37 by raphaelcarb       #+#    #+#             */
/*   Updated: 2024/11/19 13:25:29 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h> //perror
# include <string.h> //sizeof
# include <unistd.h> //dup2 close
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h> //wexitstatus
# include <fcntl.h> //pour les constantes  O_WRONLY, O_CREAT, O_TRUNC, O_APPEND 
# include <stdlib.h>
# include <signal.h> //strcut sigaction
# include <termios.h>
# include <limits.h> //path_max
# include <curses.h>
# include <term.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../LIBFT/libft.h"
# include "../LIBFT/printff/ft_printf.h"
# include "../LIBFT/get_next_linee/get_next_line.h"
# include "../LIBFT/get_next_linee/get_next_line_bonus.h"

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define RESET "\033[0m"

//extern int	g_signal;		//variable globale pour gestion des signaux

typedef enum   s_redir
{
	NO_REDIR,
	INPUT_FILE,
	HEREDOC,
	OUTPUT_FILE,
	APPEND,
}	t_redir;

//#define close(X) printf("CLOSE: %d\n", X); close(X) 

typedef struct s_cmd
{
	bool		heredoc;
	char		*delimiter;
	char		**cmd;
	char		*in_file;//fichier d entree
	char		*out_file;//fichier de sortie
	int			input_fd;//descript de fichier d entree
	int			output_fd;//descript de fichier de sortie
	struct	s_cmd	*next;
}	t_cmd;

typedef struct s_env
{
	char			*content;
	struct s_env	*next;
}	t_env;

typedef struct s_data // donnees principales
{
	char	**cut_line;
	t_env	*copy_env;
	char	*path;
	char	*pwd;
	char	*old_pwd;
	char	*line;
	int		last_exit_code;
	struct	t_cmd	*cmd;

}	t_data;

// new ============================================= ||\\    ||  ||_____|  \\        //\\        //
//	   ============================================= || \\   ||  ||_____    \\      //  \\      //
//     ============================================= ||  \\  ||  ||_____|    \\    //    \\    //
//     ============================================= ||   \\ ||  ||_____      \\  //      \\  //
//	   ============================================= ||	   \\||  ||_____|      \\//        \\//

// start in main fonction and loop

void    ft_start(char **envp);
void    ft_loop(t_env *env);
int     ft_check_quote(char *str);
int     ft_check_error(char *str);
int     ft_check_option(char *str);
int		ft_count_pipe(char *str);

//init

char    *search_in_env(t_env **env, char *name);
t_cmd	*ft_lsttnew(t_data *data, int i, t_cmd *cmd);
void	init_data_and_cmd(char *line, t_data **data, t_cmd **cmd);
void	ft_lstadd_back_list(t_env **env, t_env *new_node); // for env
void	ft_lst_addbackk(t_cmd **stack, t_cmd *node); // for cmd
int		ft_lstsizee(t_cmd *cmd);
void	shift_str(char *str, int length);
void	is_a_quote(char c, int *state);

// check redir

bool	check_if_heredoc(char *str);
char    *check_delimiteur(char *str);
void   init_heredoc(t_cmd *newnode, t_data *data, int i);
char	*ft_strncpy(char *s1, char *s2, int n);


//....................   EXECUTING.................................
//builtin->cd_builtin.c
void	ft_update_env(t_env **env, char *old_dir, char *new_dir);
void	ft_execute_cd(t_env **env, char *target_dir);
void	ft_cd(t_env **env, char **args);
//builtin->cd_utils.c
char	*ft_get_env_value(char *name, t_env **env);
char	*ft_parse_target_dir(char **args, t_env **env);
int		ft_change_directory(char *target_dir);
int		ft_check_cd_args(char **args);
//builtin->echo_builtin.c
void	ft_echo(char **argv, t_data *data, int fd);
bool	echo_n(char *argv);
void	ft_args_for_echo(char **argv, t_data *data, int fd);
//builtin->echo_utils.c
char	*ft_itoa_m(int n);
char    *ft_strjoinn(char const *s1, char const *s2);
int		check_dollard(char *str);
//builtin->env_builtin.c
void	ft_env(t_env **env);
//builtin->export_builtin.c
void	ft_export(t_env **env, char **args);
void	export_with_nothing(t_env *env);
void	export_with_variable(t_env *env, char *new_var);
//builtin->unset_builtin.c
void	unset_with_variable(t_env **env, char *my_var);
int		ft_unset(t_env **env, char **args);
//builtin->utils_builtin.c
int		is_builtin(char *cmd);
//redirection->handle_heredoc.c
static	int	handle_single_input_redir(t_cmd *cmd, t_data *data, t_redir *redir);
static  int	handle_single_output_redir(t_cmd *cmd, t_redir *redir);
void		handle_redirection(t_cmd *cmd, t_data *data);
//redirection->heredoc_file.c
static int	replace_matrice_with_heredoc_file(t_cmd *cmd);
int		ft_heredoc(t_cmd *cmd, t_data *data);
//redirection->pipe.c
void	handle_redir_fd(int src_fd, int dest_fd);
void	exec_redir(t_cmd **cmd, t_data *data, t_env **env);
int		is_builtin_parent(const char *command);
//redirection->read_heredoc.c
void	pass_redirection_and_payload(char **line, int *i); // a verifier
void	exec_trim(char **line, char **res, int *i, int j);
void	trim_redirections(char **line);
//redirection->utils_heredoc.c
void	configure_heredoc_signals(void);
void	read_input_with_heredoc(int tmp_fd, t_cmd *cmd); // a verifier
//redirection->execution.c
void	execute_command_or_builtin(t_cmd **cmd, t_env **env, t_data *data);

//executing->path.c
char	*find_command_path(char *cmd);

// signals
//---------------------------------------------------------------------------
//parse_signal.c

void	ft_handler_sig(int signal);
void	ft_handlequit(int b);
void	ft_handler_sig_cmd(int signal);
void	ft_handler_sig_hd(int signal);

// free 

void 	ft_free(char *str, t_cmd **cmd);
void 	ft_lstclearr(t_cmd **cmd);

// utils.c
char	*ft_strcpy(char *s1, char *s2);

// utils_init.c
t_env	*ft_env_new(char **envp, int i);
void	ft_change_env(t_env **env, char *name, char *new_value);
t_env	*init_env(char **envp);
void	init_pwd(t_env **env);

// split_quotes.c
char **ft_splitt(char const *s, char c);

// utils_init2.c
void	trim_quotes(char **option);

// ft_check_line_error.c
int ft_check_pipe(char *str);

#endif
