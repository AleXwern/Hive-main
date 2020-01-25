# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anystrom <anystrom@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/07 12:41:01 by anystrom          #+#    #+#              #
#    Updated: 2020/01/24 14:33:21 by anystrom         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fractol
FLG = -Wall -Wextra -Werror
SRCFILE = mou_input.c main.c help.c color.c fractol.c define_set.c key_input.c
SRC = $(addprefix ./src/,$(SRCFILE))
LIBFT = ./obj/libft.a
OBJS = $(SRC:.c=.o)
OBJ = $(addprefix ./obj/,$(SRCFILE:.c=.o))
OBJDIR = ./obj/
SRCDIR = ./src/
INCL = -I /usr/local/include -I ./libft -I ./includes
MLXLIB = ../minilibx/libmlx.a
FRAMEWORK = -lmlx -framework OpenGL -framework AppKit
RED = \033[0;31m
STOP = \033[0m

.PHONY: all clean fclean re obj

all: $(NAME)

$(LIBFT):
	@echo Compiling Libft libraries.
	@make -C ./libft

$(OBJDIR)%.o:$(SRCDIR)%.c
	@echo "Compiling Fract'ol -> $(RED)$@$(STOP)"
	@gcc $(FLG) -I ./includes -o $@ -c $<

$(NAME): $(OBJ) $(LIBFT)
	@gcc $(FLG) $(INCL) -o $(NAME) $(OBJ) $(LIBFT) $(MLXLIB) $(FRAMEWORK)
	@echo Done.

clean:
	@echo "Removing Fract'ol libraries."
	@/bin/rm -f $(OBJ)
	@echo Removing Libft libraries.
	@make -C ./libft fclean

fclean: clean
	@echo Removing binaries.
	@/bin/rm -f $(NAME)

re: fclean all
