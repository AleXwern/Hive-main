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
FLG = -Wall -Wextra -Werror
SRCFILE = fdfmain.c fileformat.c main.c input.c draw_image.c
SRC = $(addprefix ./src/,$(SRCFILE))
LIBFT = ./libft/libft.a
OBJ = $(SRC:.c=.o)
INCL = -I /usr/local/include -I ./libft -I ./includes
MLXLIB = -L /usr/local/lib/
FRAMEWORK = -lmlx -framework OpenGL -framework AppKit

.PHONY: all clean fclean re git gitrm testcomp

all: $(NAME)

$(LIBFT):
	@make -C ./libft

%.o:%.c
	gcc -I ./includes -o $@ -c $<

$(NAME): $(LIBFT) $(OBJ)
	gcc  $(FLG) $(INCL) -o $(NAME) $(OBJ) $(LIBFT) $(MLXLIB) $(FRAMEWORK)

clean:
	/bin/rm -f $(OBJ)
	make -C ./libft clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C ./libft fclean

git:
	git clone https://github.com/AleXwern/fillit-tests.git fdfmaps
	#URL REQUIRED

gitrm:
	/bin/rm -rf fdfmaps

re: fclean all