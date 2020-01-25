# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anystrom <anystrom@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/07 12:41:01 by anystrom          #+#    #+#              #
#    Updated: 2020/01/20 13:43:32 by anystrom         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fractol
FLG = -Wall -Wextra -Werror
SRCFILE = mou_input.c main.c help.c color.c fractol.c define_set.c key_input.c
SRC = $(addprefix ./src/,$(SRCFILE))
LIBFT = ./obj/libft.a
OBJS = $(SRC:.c=.o)
OBJ = $(addprefix ./obj/,$(SRCFILE:.c=.o))
INCL = -I /usr/local/include -I ./libft -I ./includes
MLXLIB = ../minilibx/libmlx.a
FRAMEWORK = -lmlx -framework OpenGL -framework AppKit
RED = \033[0;31m
STOP = \033[0m

.PHONY: all clean fclean re

all: $(NAME)

$(LIBFT):
	@echo Compiling Libft libraries.
	@make -C ./libft

%.o:%.c
	@echo "Compiling Fract'ol -> $(RED)$@$(STOP)"
	@/bin/rm -rf obj
	@/bin/mkdir obj
	@gcc $(FLG) -I ./includes -o $@ -c $<

$(NAME): $(OBJS) $(LIBFT)
	@gcc $(FLG) $(INCL) -o $(NAME) $(OBJS) $(LIBFT) $(MLXLIB) $(FRAMEWORK)
	@mv $(OBJS) ./obj
	@echo Done.

clean:
	@echo "Removing Fract'ol libraries."
	@/bin/rm -f $(OBJ)
	@echo Removing Libft libraries.
	@make -C ./libft fclean
	@/bin/rm -rf obj

fclean: clean
	@echo Removing binaries.
	@/bin/rm -f $(NAME)

re: fclean all
