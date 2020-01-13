# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anystrom <anystrom@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/07 12:41:01 by anystrom          #+#    #+#              #
#    Updated: 2020/01/13 17:12:32 by anystrom         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fractol
FLG =
SRCFILE = input.c main.c help.c color.c fractol.c
SRC = $(addprefix ./src/,$(SRCFILE))
LIBFT = ./obj/libft.a
OBJS = $(SRC:.c=.o)
OBJ = $(addprefix ./obj/,$(SRCFILE:.c=.o))
INCL = -I /usr/local/include -I ./libft -I ./includes
MLXLIB = -L /usr/local/lib/
FRAMEWORK = -lmlx -framework OpenGL -framework AppKit

.PHONY: all clean fclean re

all: $(NAME)

$(LIBFT):
	@echo Compiling Libft libraries.
	@make -C ./libft

%.o:%.c
	@echo "Compiling Fract'ol libraries."
	@/bin/rm -rf obj
	@/bin/mkdir obj
	@gcc $(FLG) -I ./includes -o $@ -c $<

$(NAME): $(OBJS) $(LIBFT)
	@echo Compiling binaries.
	@mv $(OBJS) ./obj
	@gcc  $(FLG) $(INCL) -o $(NAME) $(OBJ) $(LIBFT) $(MLXLIB) $(FRAMEWORK)
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
