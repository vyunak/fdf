# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vyunak <vyunak@student.unit.ua>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/23 10:29:46 by vyunak            #+#    #+#              #
#    Updated: 2019/05/23 10:29:47 by vyunak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fdf
FILENAME	=	fdf fdf_key fdf_map fdf_img fdf_img_2
FLAGS		=	-Wall -Wextra -Werror
FLAGS_MLX	= 	-I minilibx_macos/ -I libft/ -L minilibx_macos/ -L libft/ -framework OpenGL -framework AppKit -lm -lmlx libft/libft.a
OBJECTS		=	$(FILENAME:=.o)
FILE		=	$(addprefix src/, $(FILENAME:=.c))

all: $(NAME)

$(NAME): $(FILE)
	@make -C libft
	@make -C minilibx_macos
	gcc -c $(FILE)
	gcc $(OBJECTS) $(FLAGS) $(FLAGS_MLX) -o $(NAME)

clean:
	rm -f $(OBJECTS)
	@make clean -C libft

fclean: clean
	rm -f $(NAME)
	@make fclean -C libft
	@rm -f *.gch .DS_Store

re: fclean $(NAME)

.PHONY: clean fclean all re
