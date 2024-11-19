# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spagliar <spagliar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/03 18:39:18 by raphaelcarb       #+#    #+#              #
#    Updated: 2024/11/18 17:30:42 by spagliar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
CFLAGS = -g3 #-Werror -Wall -Wextra
LDFLAGS = -lreadline -ltinfo
EXE = minishell
RM = rm -rf

LIBFT_PATH = ./LIBFT
LIBFT = $(LIBFT_PATH)/libft.a

src = executing/path.c\
		executing/builtin/cd_builtin.c\
		executing/builtin/cd_utils.c\
		executing/builtin/echo_builtin.c\
		executing/builtin/echo_utils.c\
		executing/builtin/env_builtin.c\
		executing/builtin/export_builtin.c\
		executing/builtin/unset_builtin.c\
		executing/builtin/utils_builtin.c\
		parsing/init.c \
		parsing/utils_init.c \
		parsing/utils_init2.c \
		parsing/utils.c \
		parsing/start.c \
		parsing/ft_check_line_error.c \
		parsing/split_quote.c \
		parsing/check_redirection.c \
		parsing/check_heredoc.c \
		parsing/ft_free.c \
		main.c 

srco = $(src:.c=.o)

all: $(EXE)

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

$(EXE): $(srco) $(LIBFT)
	$(CC) $(CFLAGS) $(src) $(LIBFT) -o $(EXE) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(srco)
	$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	$(RM) $(EXE)
	$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
