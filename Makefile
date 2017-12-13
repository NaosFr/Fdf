# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncella <ncella@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/22 14:43:15 by ncella            #+#    #+#              #
#    Updated: 2017/12/09 11:01:15 by ncella           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC_NAME = main.c ft_key.c ft_read.c ft_check_map.c ft_draw.c ft_put_map.c \
			ft_color.c ft_info.c ft_init.c ft_algo.c 
SRC = $(addprefix srcs/, $(SRC_NAME))
OBJ = $(patsubst srcs/%.c, obj/%.o, $(SRC))
CFLAGS = -Wall -Wextra -Werror -I libft/ -I minilibx_macos/
LIBS = -framework OpenGL -framework AppKit libft/libft.a minilibx_macos/libmlx.a 

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/ fclean && make -C libft/
	@gcc $(CFLAGS) -o $(NAME) $(LIBS) $(OBJ)
	@echo "\033[32mFdF compiled [ ✔ ]"

obj/%.o: srcs/%.c
	@mkdir -p obj
	@gcc $(CFLAGS) -c $< -o $@

clean:
	@rm -rf obj/
	@make -C libft/ fclean
	@echo "\033[32mFdF cleaned [ ✔ ]"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[32mFdF fcleaned [ ✔ ]"

re: fclean all

.PHONY: all clean fclean re
