# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anystrom <anystrom@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/30 16:09:13 by anystrom          #+#    #+#              #
#    Updated: 2020/06/10 15:32:23 by anystrom         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
FLG = -Wall -Wextra -Werror
SRCFILE = fdfmain.c fileformat.c main.c input.c draw_image.c dim_fileformat.c
SRC = $(addprefix ./src/,$(SRCFILE))
LIBFT = ./libft/libft.a
OBJ = $(SRC:.c=.o)
INCL = -I /usr/local/include -I ./libft -I ./includes
MLXLIB = -L /usr/local/lib
FRAMEWORK = -lmlx -framework OpenGL -framework AppKit

.PHONY: all clean fclean re git gitrm testcomp

all: $(NAME)

$(LIBFT):
	@make -C ./libft

%.o:%.c
	gcc $(FLG) -I ./includes -o $@ -c $<

$(NAME): $(LIBFT) $(OBJ)
	gcc  $(FLG) $(INCL) -o $(NAME) $(OBJ) $(LIBFT) $(MLXLIB) $(FRAMEWORK)

clean:
	/bin/rm -f $(OBJ)
	make -C ./libft clean

fclean: clean gitrm
	/bin/rm -f $(NAME)
	make -C ./libft fclean

git:
	git clone https://github.com/AleXwern/fillit-tests.git tests
	mv ./tests/maps ./
	rm -rf tests/

gitrm:
	/bin/rm -rf maps
	/bin/rm -rf tests

re: fclean all
