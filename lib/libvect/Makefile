# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scollon <scollon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 13:40:40 by scollon           #+#    #+#              #
#    Updated: 2016/02/08 13:40:10 by scollon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC_PATH	= ./src/
OBJ_PATH	= ./obj/
INC_PATH	= ./includes/

NAME 		= libvect.a
CC 			= gcc
CFGLAGS 	= -Werror -Wextra -Wall

SRC_NAME  	=	vec_create.c vec_add.c vec_sub.c vec_mult.c \
			vec_div.c vec_magnitude.c vec_norm.c vec_scale.c \
			vec_rotate.c vec_to_int.c int_to_vec.c \
			vec3_create.c vec3_add.c vec3_sub.c \
			vec3_mult.c vec3_mult_vec.c vec3_div.c \
			vec3_magnitude.c vec3_norm.c vec3_scale.c \
			vec3_dot_product.c vec3_up.c vec3_right.c vec3_forward.c \
			vec3_rotate.c vec3_cross_product.c vec3_clamp.c


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
