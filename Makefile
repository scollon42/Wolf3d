# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scollon <scollon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/01 10:19:30 by scollon           #+#    #+#              #
#*   Updated: 2016/01/21 18:34:15 by                  ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./includes/
LIB_PATH = ./lib/
INC_LIBFT_PATH = $(LIB_PATH)libft/includes/ $(LIB_PATH)libvect/includes/
MLX_PATH = $(LIB_PATH)mlx/

NAME = wolf3d
CC = gcc
CFGLAGS = -Werror -Wextra -Wall
MLX = -L$(MLX_PATH) -I$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit

SRC_NAME = main.c env.c core.c render.c event.c map.c sprites.c quit.c
OBJ_NAME = $(SRC_NAME:.c=.o)
LIB_NAME = libft/libft.a libvect/libvect.a

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))
INC_LIBFT = $(addprefix -I,$(INC_LIBFT_PATH))
LIB = $(addprefix $(LIB_PATH),$(LIB_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@#make -C $(LIB_PATH)libft re
	@#make -C $(LIB_PATH)libvect re
	@#make -C $(LIB_PATH)mlx re
	$(CC) $(CFLAGS) $(MLX) $(LIB) $(INC_LIBFT) $(INC) $(OBJ) -o $(NAME)
	@#$(MAKE) check

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2>/dev/null || echo "" > /dev/null
	$(CC) $(CFLAGS) $(INC_LIBFT) $(INC) -o $@ -c $<

.PHONY: clean fclean re check fclean_libft clean_libft

clean:
	rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null

clean_libft:
	make -C libft clean

fclean: clean
	rm -f $(NAME)

fclean_libft:
	make -C libft fclean

re: fclean all

check:
	@ls libft | grep -q libft.a && echo "\033[1mLIBFT\033[0m      [\033[32mOK\033[0m]" \
							    || echo "\033[1mLIBFT\033[0m      [\033[31mKO\033[0m]"
	@ls mlx | grep -q libmlx.a && echo "\033[1mMLX\033[0m        [\033[32mOK\033[0m]" \
							   || echo "\033[1mMLX\0330m [\033[31mKO\033[0m]"
	@ls | grep -q -U wolf3d && echo "\033[1mWOLF3D\033[0m     [\033[32mOK\033[0m]" \
							 || echo "\033[1mWOLF3D\033[0m     [\033[31mKO\033[0m]"
	@ls | grep -q auteur && echo "\033[1mAUTEUR\033[0m     [\033[32mOK\033[0m]" \
					     || echo "\033[1mAUTEUR\033[0m     [\033[31mKO\033[0m]"
	@norminette src/ includes/ libft/src/ libft/includes/ | grep -B 1 Error && \
		echo "\033[1mNORMINETTE\033[0m [\033[31mKO\033[0m]" \
	 || echo "\033[1mNORMINETTE\033[0m [\033[32mOK\033[0m]"
