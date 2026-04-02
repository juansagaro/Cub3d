# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsagaro- <jsagaro-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/14 13:35:50 by fgalvez-          #+#    #+#              #
#    Updated: 2026/01/03 18:23:06 by jsagaro-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                   MAKEFILE                                   #
# **************************************************************************** #

NAME        = cub3d
NAME_BONUS  = cub3d_bonus

CC          = cc
# Recomendado: -O3 para optimizar gráficos, -g3 para valgrind/debug
CFLAGS      = -Wall -Wextra -Werror -g3 -O3
RM          = rm -f

# ========================= LIBRERÍAS ======================================== #

LIBFT_DIR   = mandatory/inc/libft
GNL_DIR     = mandatory/inc/gnl
MLX_DIR     = mandatory/inc/minilibx-linux

# Flags de enlazado (LIBRARIES)
# IMPORTANTE: El orden importa. MLX primero, luego X11 y Math (-lm)
LIBS_FLAGS  = -L$(LIBFT_DIR) -lft -L$(GNL_DIR) -lgnl
MLX_LIBS    = -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm -lz

INCLUDES    = -I$(LIBFT_DIR) -I$(GNL_DIR) -I$(MLX_DIR)

# ========================= MANDATORY ======================================== #

M_DIR       = mandatory/src/
M_INC       = -Imandatory/inc

M_FILES     =   main.c \
                parser/parse_main.c \
                parser/parse_read.c \
                parser/parse_map.c \
                parser/parse_validate.c \
                parser/parse_player.c \
                parser/parse_textures.c \
                parser/parse_colors.c \
                parser/parse_utils.c \
                inits/init_data.c \
                inits/init_mlx.c \
                inits/init_assets.c \
                inits/init_dda.c \
                inputs/input_setup.c \
                inputs/input_keyboard.c \
                logic/player_move.c \
                render/rc_loop.c \
                render/rc_dda.c \
                render/draw_walls.c \
                render/draw_fl_ceil.c \
                render/draw_utils.c \
                core/game_loop.c \
                cleanup/clean_data.c \
                cleanup/clean_exit.c \
                utils/utils_mem.c \
                utils/utils_debug.c

SRCS_MAN    = $(addprefix $(M_DIR), $(M_FILES))
OBJS_MAN    = $(addprefix obj/mandatory/, $(M_FILES:.c=.o))

# ========================= BONUS ============================================ #

B_DIR       = bonus/src/
B_INC       = -Ibonus/inc

B_FILES     =   main.c \
                parser/parse_main.c \
                parser/parse_read.c \
                parser/parse_map.c \
                parser/parse_validate.c \
                parser/parse_player.c \
                parser/parse_textures.c \
                parser/parse_colors.c \
                parser/parse_utils.c \
                inits/init_data.c \
                inits/init_mlx.c \
                inits/init_assets.c \
                inits/init_dda.c \
                inputs/input_setup.c \
                inputs/input_keyboard.c \
                inputs/input_mouse.c \
                logic/player_move.c \
                logic/player_actions.c \
                render/rc_loop.c \
                render/rc_dda.c \
                render/draw_walls.c \
                render/draw_fl_ceil.c \
                render/draw_minimap.c \
                render/draw_weapon.c \
                render/draw_utils.c \
                core/game_loop.c \
                cleanup/clean_data.c \
                cleanup/clean_exit.c \
                utils/utils_mem.c \
                utils/utils_debug.c

SRCS_BON    = $(addprefix $(B_DIR), $(B_FILES))
OBJS_BON    = $(addprefix obj/bonus/, $(B_FILES:.c=.o))

# ========================= COLORES ========================================== #
GREEN       = \033[0;32m
YELLOW      = \033[0;33m
CYAN        = \033[0;36m
MAGENTA     = \033[0;35m
RESET       = \033[0m
RED         = \033[0;31m

# ========================= REGLAS PRINCIPALES =============================== #

.PHONY: all clean fclean re libft gnl mlx bonus

all: libft gnl mlx $(NAME)

$(NAME): $(OBJS_MAN)
	@echo "\n${MAGENTA}Enlazando MANDATORY: $(NAME)...${RESET}"
	$(CC) $(OBJS_MAN) $(CFLAGS) $(MLX_LIBS) $(LIBS_FLAGS) -o $(NAME)
	@echo "${GREEN}[✔] Compilación Mandatory completada.${RESET}"

bonus: libft gnl mlx $(OBJS_BON)
	@echo "\n${MAGENTA}Enlazando BONUS: $(NAME_BONUS)...${RESET}"
	$(CC) $(OBJS_BON) $(CFLAGS) $(MLX_LIBS) $(LIBS_FLAGS) -o $(NAME_BONUS)
	@echo "${GREEN}[✔] Compilación Bonus completada.${RESET}"

# ========================= REGLAS DE OBJETOS ================================ #

obj/mandatory/%.o: $(M_DIR)%.c
	@mkdir -p $(dir $@)
	@echo "${CYAN}Compilando [MAN]: $<${RESET}"
	$(CC) $(CFLAGS) $(INCLUDES) $(M_INC) -c $< -o $@

obj/bonus/%.o: $(B_DIR)%.c
	@mkdir -p $(dir $@)
	@echo "${CYAN}Compilando [BON]: $<${RESET}"
	$(CC) $(CFLAGS) $(INCLUDES) $(B_INC) -c $< -o $@

# ========================= LIBRERÍAS EXTERNAS =============================== #

libft:
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR)

gnl:
	@$(MAKE) --no-print-directory -C $(GNL_DIR)

mlx:
	@echo "${YELLOW}Compilando MiniLibX...${RESET}"
	@$(MAKE) -C $(MLX_DIR) > /dev/null

# ========================= LIMPIEZA ========================================= #

clean:
	@echo "${YELLOW}Limpiando objetos...${RESET}"
	$(RM) -r obj/
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) clean
	@$(MAKE) --no-print-directory -C $(GNL_DIR) clean
	@$(MAKE) --no-print-directory -C $(MLX_DIR) clean

fclean: clean
	@echo "${RED}Eliminando ejecutables...${RESET}"
	$(RM) $(NAME) $(NAME_BONUS)
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) fclean
	@$(MAKE) --no-print-directory -C $(GNL_DIR) fclean

re: fclean all bonus