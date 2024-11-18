/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spagliar <spagliar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:12:37 by raphaelcarb       #+#    #+#             */
/*   Updated: 2024/11/18 15:24:39 by spagliar         ###   ########.fr       */
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

//....................   EXECUTING.................................
// path.c
char	*find_command_path(char *cmd);
//builtin->echo_builtin.c
void	ft_echo(char **argv, t_data *data, int fd);
char    *cut_tab_dollard(char *str);
//export.c

void    export_with_nothing(t_env *env);
void    export_with_variable(t_env *env, char *new_var);
void    ft_export(t_env **env, char **args);
//unset.c

void    unset_with_variable(t_env **env, char *my_var);
int     ft_unset(t_env **env, char **args);
//  cd.c

void    ft_change_cd(t_env **env, char *new_dir);
void    ft_change_env(t_env **env, char *name, char *new_value);
char	*ft_get_env_value(char *name, t_env **env);
void	ft_change_env(t_env **env, char *name, char *new_value);
int		ft_change_directory(char *target_dir);
void	ft_update_env(t_env **env, char *old_pwd, char *new_pwd);
void	ft_execute_cd(t_env **env, char *target_dir);
void	ft_cd(t_env **env, char **target_dir);
void	init_pwd(t_env **env);

//	env.c

void	ft_env(t_env **env);

//ft_pwd.c

int    ft_pwd(void);

//	utils_builtins.c

int		is_builtin(char *cmd);
// EXEC
//---------------------------------------------------------------------------
// path.c

char	*find_command_path(char *cmd);

//INIT
//--------------------------------------------------------------------
// init_lst

void	ft_lstadd_back_list(t_env **env, t_env *n);
t_env	*ft_env_new(char **envp, int i);
void	ft_change_env(t_env **env, char *name, char *new_value);

void	init_data(t_data *data);
void	init_cmd(t_cmd *cmd);
t_cmd	*ft_lsttnew(t_data *data, int i, t_cmd *cmd);

//init

void    init_pwd(t_env **env);
void    init_data(t_data *data, char *str);
void    init_cmd(t_cmd *cmd);
t_env	*init_env(char **envp);

// parsing
//------------------------------------------------------------------
//->ft_utils_cmd.c
void	ft_lst_addbackk(t_cmd **stack, t_cmd *node);
int		ft_lstsizee(t_cmd *cmd);
void	ft_lstclearr(t_cmd **cmd);
void	ft_free(char *str, t_cmd **cmd);

//->option.c

char	*ft_check_dash(char *str);

//->parsing1.c

void	ft_do_all(char *str, t_cmd **cmd, t_data *data, t_cmd *new_node);

// utils

int		ft_strcmp(const char *s1, const char *s2);
void	print_minishell(void);
char	**ft_strdup_tab(char **env);
char	*ft_strcpy(char	*s1 , char *s2);
char	*ft_strncpy(char *s1, char *s2, int n);
char    *ft_get_env_value(char *name, t_env **env);
char    *ft_tab(char **av);
int     ft_lstsizee(t_cmd *cmd);

//utils_env

char	**env_list_to_array(t_env **env_list);
int   ft_strncmp_env(const char *s1, const char *s2, size_t n);

//->parsing2.c

int		ft_check_pipe(char *str);

//->utils_parsing_line

int		ft_isspace(char c);
void	stock_filename(t_cmd *cmd, const char *start, int j);
char	*ft_extract_delimiter(t_cmd *cmd, t_data *data);

//->utils_parsing.c

int		count_pipe(char *str);
//void	ft_cut_cont(char *str, t_data *data); a refaire
int		ft_check_one_quote(char *str);

//pipe
//pipe.c

void	handle_redir_fd(int src_fd, int dest_fd);
void	exec_redir(t_cmd **cmd, t_data *data, t_env **env);
int		is_builtin_parent(const char *command);
void	execute_builtin_in_parent(t_cmd *cmd, t_env **env);
//utils_pipe.c
//path.c

char	*find_command_path(char *cmd);

//signaux
void	ft_handler(int a);
void	ft_handlequit(int b);
// redirection
//-----------------------------------------------------------------
//->handle_heredoc.c

void	handle_redirection(t_cmd *cmd, t_data *data);
//->heredoc_file.c

int		ft_heredoc(t_cmd *cmd, t_data *data);
//->read_heredoc.c

void	pass_redirection_and_payload(char **line, int *i); // a verifier
void	exec_trim(char **line, char **res, int *i, int j);
void	trim_redirections(char **line);
//->utils_heredoc.c

void	configure_heredoc_signals();
void	read_input_with_heredoc(int tmp_fd, t_cmd *cmd); // a verifier
// signals
//---------------------------------------------------------------------------
//parse_signal.c

void	ft_handler_sig(int signal);
void	ft_handlequit(int b);
void	ft_handler_sig_cmd(int signal);
void	ft_handler_sig_hd(int signal);


// free

void	ft_free_tab(char **av);

// read_line.c

void	ft_check_line(t_data *data, t_cmd **cmd, t_env **env); // a revoir
void	detect_output_redirection(t_cmd *cmd, t_data *data, int *i, int *j); // a revoir
void	detect_input_redirection(t_cmd *cmd, t_data *data, int *i, int *j); // a revoir
void	detect_redirection(t_cmd *cmd, t_data *data); // a revoir

// utils_env

char	**env_list_to_array(t_env **env_list);
int	    ft_verifcharr(char c, char set);
char	*ft_strdupsizee(const char *s, int size);
int	    ft_nbredemott(char const*s, char c);
char	**ft_splitt(char const *s, char c);

int     ft_is_in_quote(char *str, int i);
int     ft_is_in_doublequote(char *str, int i);

void	is_a_quote(char c, int *state);
void	shift_str(char *str, int length);
void	trim_quotes(char **option);
char    *search_in_env(t_env **env, char *name);
char    *ft_strjoin_char(char *s1, char c);
char    *ft_strjoinn(char const *s1, char const *s2);
int     ft_is_valid_export(char **mat);
void    read_env_changes_from_pipe(int fd, t_env **env);
void    exec_builtin_with_changes(t_cmd *cmd, t_env **env);
void    unsetenv_in_list(t_env **env, char *name);
void    setenv_in_list(t_env **env, char *name, char *value);
int 	is_builtin_parent(const char *command);
void 	execute_builtin_in_parent(t_cmd *cmd, t_env **env);
//pipe_utils
char 	*last_exit(t_data *data);
//																   _____
// new ============================================= ||\\    ||  ||_____|  \\        //\\        //
//	   ============================================= || \\   ||  ||_____    \\      //  \\      //
//     ============================================= ||  \\  ||  ||_____|    \\    //    \\    //
//     ============================================= ||   \\ ||  ||_____      \\  //      \\  //
//	   ============================================= ||	   \\||  ||_____|      \\//        \\//

// start in main fonction and loop

void    ft_start(char **envp);
void    ft_loop(t_env *env);

// error before loop  

int     ft_check_quote(char *str);
int     ft_check_error(char *str);
int     ft_check_option(char *str);
int		ft_count_pipe(char *str);

//init

char    *search_in_env(t_env **env, char *name);
t_cmd	*ft_lsttnew(t_data *data, int i, t_cmd *cmd);
void	init_data_and_cmd(char *line, t_data *data, t_cmd **cmd);
void	ft_lstadd_back_list(t_env **env, t_env *new_node); // for env
void	ft_lst_addbackk(t_cmd **stack, t_cmd *node); // for cmd
int		ft_lstsizee(t_cmd *cmd);

//split_quote

char 	**ft_splitt(char const *s, char c);
int 	ft_nbredemott(char const *s, char c);
char 	*ft_strdupsizee(const char *s, int size);
int		ft_is_in_doublequote(char *str, int i);
int		ft_is_in_quote(char *str, int i);
void	trim_quotes(char **option);
void	shift_str(char *str, int length);
void	is_a_quote(char c, int *state);

// check redir

bool	check_if_heredoc(char *str);
char    *check_delimiteur(char *str);
void   init_heredoc(t_cmd *newnode, t_data *data, int i);
char	*ft_strncpy(char *s1, char *s2, int n);

#endif
