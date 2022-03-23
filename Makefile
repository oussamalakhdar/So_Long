# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olakhdar <olakhdar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 11:08:06 by olakhdar          #+#    #+#              #
#    Updated: 2022/03/23 18:55:54 by olakhdar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ./mandatory/so_long

BONUS = ./bonus/so_long

CC = gcc

FLAGS =	-Wall -Werror -Wextra

FILES = ./mandatory/so_long.c ./mandatory/so_long_utils.c ./mandatory/ft_split.c \
		./mandatory/get_next_line.c ./mandatory/draw.c  ./mandatory/allocation.c \
		./mandatory/get_next_line_utils.c ./mandatory/keyhook.c \
		./mandatory/printf.c ./mandatory/checkchar.c \

BFILES = ./bonus/so_long_bonus.c ./bonus/so_long_bonus_utils.c ./bonus/ft_split_bonus.c \
		./bonus/get_next_line.c ./bonus/draw_bonus.c ./bonus/sprite.c \
		./bonus/get_next_line_utils.c ./bonus/ft_itoa.c ./bonus/keyhook_bonus.c \
		./bonus/allocation_bonus.c ./bonus/checkchar_bonus.c \

all: $(NAME)

bonus: $(BONUS)

$(NAME):
	$(CC) $(FLAGS) $(FILES) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(BONUS):
	$(CC) $(FLAGS) $(BFILES) -lmlx -framework OpenGL -framework AppKit -o $(BONUS)
clean:
	rm -f $(NAME) $(BONUS)

fclean: clean

re: fclean all