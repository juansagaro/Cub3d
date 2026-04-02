# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/08 14:04:17 by fgalvez-          #+#    #+#              #
#    Updated: 2025/09/14 13:58:00 by fgalvez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ========================= VARIABLES GLOBALES =============================== #

NAME   = libgnl.a
CC     = cc
CFLAGS = -Wall -Wextra -Werror
RM     = rm -f

SEP = ================================================================================================================

# ========================= DIRECTORIOS Y ARCHIVOS =========================== #

OBJ_DIR = obj

SRCS = get_next_line.c \
		get_next_line_utils.c

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

# ========================= COLORES PARA EL OUTPUT =========================== #

GREEN   = \033[0;32m
YELLOW  = \033[0;33m
CYAN    = \033[0;36m
MAGENTA = \033[0;35m
RESET   = \033[0m
RED     = \033[0;31m

# ========================= REGLAS =========================================== #

.PHONY: all clean fclean re

all: $(NAME)
	@echo "${GREEN}[✔] Todo listo: $(NAME) compilada.${RESET}"

$(NAME): $(OBJS)
	@echo "\n${MAGENTA}Compilando la biblioteca estática $(NAME)...${RESET}\n"
	ar rcs $@ $^
	@echo "${CYAN}$(SEP)${RESET}"
	@echo "${GREEN}                             [✔] $(NAME) compilada correctamente.${RESET}"
	@echo "${CYAN}$(SEP)${RESET}"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)  # Crea el directorio de objetos si no existe
	@echo "${CYAN}Compilando objeto:${RESET} $<"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "${YELLOW}Limpiando archivos objeto de gnl...${RESET}"
	$(RM) -r $(OBJ_DIR)

fclean: clean
	@echo "${RED}Eliminando la biblioteca $(NAME)...${RESET}"
	$(RM) $(NAME)

re: fclean all
