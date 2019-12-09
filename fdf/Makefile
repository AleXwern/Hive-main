# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anystrom <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/30 16:09:13 by anystrom          #+#    #+#              #
#    Updated: 2019/11/03 14:50:54 by anystrom         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRCFILE = main.c
SRC = $(addprefix ./src/,$(SRCFILE))
LIBFT = ./libft/libft.a
OBJ = $(SRC:.c=.o)
INCL = -I /usr/local/include -I ./libft -I ./includes
CAPL = -L /usr/local/lib/
FRAMEWORK = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(LIBFT):
	@make -C ./libft

%.o:%.c
	gcc -I ./includes -o $@ -c $<

$(NAME): $(LIBFT) $(OBJ)
	gcc $(INCL) -o $(NAME) $(OBJ) $(LIBFT) $(CAPL) $(FRAMEWORK)

clean:
	/bin/rm -f $(OBJ)
	make -C ./libft clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C ./libft fclean

re: fclean all