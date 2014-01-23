# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/22 19:43:07 by ebaudet           #+#    #+#              #
#    Updated: 2014/01/22 19:43:07 by ebaudet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= filler
FILES	= main.c eb_get_data.c eb_find_pos.c eb_test.c
SRCS	= $(addprefix src/, $(FILES))
OBJS	= $(SRCS:src/%.c=.obj/%.o)
INC		= -I includes -I libft/includes
FLAGS	= -Wall -Wextra -Werror
LIB		= -L libft -lft

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	cc $(FLAGS) $(SRCS) -o $(NAME) $(INC) $(LIB)

.obj/%.o: src/%.c
	mkdir -p .obj
	cc -c $< -o $@ $(FLAGS) $(INC)

gdb:
	make -C libft
	cc -g $(FLAGS) $(SRCS) -o $(NAME) $(INC) $(LIB)
	gdb $(NAME)

exec:
	~/ruby-2.1.0/bin/./ruby vm_beta.rb -f maps/map1.map -p1 \
	~/rendu/algorithmie_1/Filler/work/filler -p2 \
	~/rendu/algorithmie_1/Filler/work/bin/hcao.filler

clean:
	rm -rf .obj

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re exec gdb
