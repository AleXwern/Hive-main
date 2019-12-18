# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pkuussaa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/13 16:33:43 by pkuussaa          #+#    #+#              #
#    Updated: 2019/11/26 18:24:03 by pkuussaa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLG = -Wall -Wextra -Werror
NAME = fillit
FILE = get_next_line/get_next_line.c check_valid.c free_memory.c \
		map_manager.c tetri_list.c solver.c main.c
OBJ = $(FILE:.c=.o)
LIBFT = ./libft/libft.a

.PHONY: all clean fclean re git gitrm

all: $(NAME)

$(LIBFT):
	@make -C ./libft

%.o:%.c
	@gcc $(FLG) -I ./ -o $@ -c $<

$(NAME): $(LIBFT) $(OBJ)
	@echo "Compiling...."
	@gcc $(FLG) -I ./ -I ./libft/ -I ./get_next_line/ -o $(NAME) $(LIBFT) $(OBJ)
	@echo "Done."

clean:
	@/bin/rm -f $(OBJ)
	@make -C ./libft clean

fclean: clean
	@echo "Removing executable."
	@/bin/rm -f $(NAME)
	@make -C ./libft fclean

gitrm:
	@echo "Removing testfiles."
	@/bin/rm -rf tests

git:
	@git clone https://github.com/AleXwern/fillit-tests.git tests

re: fclean all
