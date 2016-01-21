# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scollon <scollon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 13:40:40 by scollon           #+#    #+#              #
#    Updated: 2016/01/21 08:38:05 by scollon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./includes/

NAME = libvect.a
CC = gcc
CFGLAGS = -Werror -Wextra -Wall

SRC_NAME  = vec_create.c vec_add.c vec_sub.c vec_cmp.c vec_mult.c vec_div.c \
			vec_magnitude.c vec_norm.c vec_scale.c vec_rotate.c vec_to_int.c \
			int_to_vec.c

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2>/dev/null || echo "" > /dev/null
	$(CC) $(CFLAGS) $(LIB) $(INC) -o $@ -c $<

.PHONY: clean fclean re

clean:
	rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null

fclean: clean
	rm -f $(NAME)

re: fclean all
