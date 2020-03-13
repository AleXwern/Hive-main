# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: JessicaNystrom <JessicaNystrom@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/07 12:41:01 by anystrom          #+#    #+#              #
#    Updated: 2020/03/13 12:18:30 by JessicaNyst      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = wolf3d
FLG =
SRCFILE = wolf.c fileformat.c gfx.c key_input.c render.c draw.c move.c randenc.c
SRC = $(addprefix ./src/,$(SRCFILE))
LIBFT = ./obj/libft.a
OBJS = $(SRC:.c=.o)
OBJ = $(addprefix ./obj/,$(SRCFILE:.c=.o))
OBJDIR = ./obj/
SRCDIR = ./src/
INCL = -I /usr/X11/include -I ./libft -I ./includes -I /usr/local/include
MLXLIB = -L /usr/X11/lib
FRAMEWORK = -lX11 -lmlx -lXext -framework OpenGL -framework AppKit
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

clean:
	@echo "Removing Wolf3D libraries."
	@/bin/rm -f $(OBJ)
	@echo Removing Libft libraries.
	@make -C ./libft fclean

fclean: clean
	@echo Removing binaries.
	@/bin/rm -f $(NAME)

re: fclean all
