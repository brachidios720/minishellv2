# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spagliar <spagliar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/03 18:39:18 by raphaelcarb       #+#    #+#              #
#    Updated: 2024/11/16 15:16:15 by spagliar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
CFLAGS = -Wall -Werror -Wextra -g3
LDFLAGS = -lreadline -ltinfo
EXE = Minishell
RM = rm -rf

LIBFT_PATH = ./LIBFT
LIBFT = $(LIBFT_PATH)/libft.a

src = executing/path.c\
		executing/builtin/cd_builtin.c\
		executing/builtin/cd_utils.c\
		executing/builtin/echo_builtin.c\
		executing/builtin/echo_utils.c\
		parsing/init.c \
		parsing/utils_init.c \
		parsing/utils.c \
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
