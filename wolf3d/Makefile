# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anystrom <anystrom@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/07 12:41:01 by anystrom          #+#    #+#              #
#    Updated: 2020/06/15 14:17:25 by anystrom         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = wolf3d
FLG =
SRCFILE = wolf.c fileformat.c gfx.c key_input.c render.c draw.c move.c randenc.c \
			floor.c randkey.c interact.c util.c anim.c ai.c entity.c cursor.c
TESTFILE = testkey.c
SRC = $(addprefix ./src/,$(SRCFILE))
LIBFT = ./obj/libft.a
OBJS = $(SRC:.c=.o)
OBJ = $(addprefix ./obj/,$(SRCFILE:.c=.o))
OBJDIR = ./obj/
SRCDIR = ./src/
INCL = -I /usr/local/include -I ./libft -I ./includes
MLXLIB = -L /usr/local/lib
FRAMEWORK = -lmlx -framework OpenGL -framework AppKit
RED = \033[0;31m
STOP = \033[0m

.PHONY: all clean fclean re obj

all: $(NAME)

$(LIBFT):
	@echo Compiling Libft libraries.
	@make -C ./libft

$(OBJDIR)%.o:$(SRCDIR)%.c
	@echo "Compiling Wolf3D -> $(RED)$@$(STOP)"
	@gcc $(FLG) -I ./includes -o $@ -c $<

$(NAME): $(OBJ) $(LIBFT)
	gcc $(FLG) $(INCL) -o $(NAME) $(OBJ) $(LIBFT) $(MLXLIB) $(FRAMEWORK)
	@echo Done.

test: $(LIBFT)
	gcc $(INCL) -o $(NAME) testkey.c $(LIBFT) $(MLXLIB) $(FRAMEWORK)

clean:
	@echo "Removing Wolf3D libraries."
	@/bin/rm -f $(OBJ)
	@echo Removing Libft libraries.
	@make -C ./libft fclean

fclean: clean
	@echo Removing binaries.
	@/bin/rm -f $(NAME)

git:
	git clone https://github.com/AleXwern/fillit-tests.git tests
	mv ./tests/map3d ./
	rm -rf tests/

gitclean:
	/bin/rm -rf map3d
	/bin/rm -rf tests

re: fclean all
