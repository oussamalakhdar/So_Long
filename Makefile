# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olakhdar <olakhdar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 11:08:06 by olakhdar          #+#    #+#              #
#    Updated: 2022/03/15 11:56:34 by olakhdar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ./mandatory/so_long

CC = gcc

FLAGS =	-Wall -Werror -Wextra 

FILES = ./mandatory/so_long.c ./mandatory/so_long_utils.c ./mandatory/ft_split.c \
		./mandatory/get_next_line.c ./mandatory/draw.c \
		./mandatory/get_next_line_utils.c ./mandatory/ft_itoa.c ./mandatory/keyhook.c \

all: $(NAME)

$(NAME):
	$(CC) $(FILES) $(FLAGS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all