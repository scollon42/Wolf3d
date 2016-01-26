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

SRC_PATH 			= ./src/
OBJ_PATH 			= ./obj/
INC_PATH 			= ./includes/
LIB_PATH 			= ./lib/
SDL2				= -framework SDL2
SDL2_MIXER			= -framework SDL2_mixer

SDL2_HEADER			= -I ~/Library/Frameworks/SDL2.framework/Headers/
SDL2_HEADER_MIXER	= -I ~/Library/Frameworks/SDL2_mixer.framework/Headers/

SDL        			= -F ~/Library/Frameworks $(SDL2_MIXER) $(SDL2)
SDL_HEADER 			= -F ~/Library/Frameworks $(SDL2_HEADER_MIXER) $(SDL2_HEADER)
INC_LIBFT_PATH 		= $(LIB_PATH)libft/includes/ $(LIB_PATH)libvect/includes/
MLX_PATH 			= $(LIB_PATH)mlx/
MLX					= -L$(MLX_PATH) -I$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit

NAME				= wolf3d
CC 					= gcc
CFGLAGS 			= -Werror -Wextra -Wall

SRC_NAME 			= main.c env.c core.c action.c render.c event.c \
					  map.c sprites.c raycast.c raycast_text.c \
					  texture.c utils.c quit.c
OBJ_NAME 			= $(SRC_NAME:.c=.o)
LIB_NAME 			= libft/libft.a libvect/libvect.a

SRC 				= $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ 				= $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC 				= $(addprefix -I,$(INC_PATH))
INC_LIBFT 			= $(addprefix -I,$(INC_LIBFT_PATH))
LIB 				= $(addprefix $(LIB_PATH),$(LIB_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB_PATH)libft re
	@make -C $(LIB_PATH)libvect re
	@make -C $(LIB_PATH)mlx re
	$(CC) $(CFLAGS) $(MLX) $(SDL) $(SDL_HEADER) $(LIB) $(INC_LIBFT) $(INC) $(OBJ)  -o $(NAME)

nl: fclean $(OBJ)
	$(CC) $(CFLAGS) $(MLX) $(SDL) $(SDL_HEADER) $(LIB) $(INC_LIBFT) $(INC) $(OBJ)  -o $(NAME)



$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2>/dev/null || echo "" > /dev/null
	$(CC) $(CFLAGS) $(INC_LIBFT) $(SDL_HEADER) $(INC) -o $@ -c $<

.PHONY: clean fclean re mrpropper sdl_install

clean:
	rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null


fclean: clean
	rm -f $(NAME)


re: fclean all

mrpropper: fclean
	make -C lib/libft/ fclean
	make -C lib/libvect/ fclean
	make -C lib/mlx/ clean

sdl_install:
	    curl https://dl.dropboxusercontent.com/u/22561204/SDL/Archive.zip > /tmp/Archive.zip
		unzip -o /tmp/Archive.zip -d ~/Library/Frameworks/
