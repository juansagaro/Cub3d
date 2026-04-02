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

NAME   = libft.a
CC     = cc
CFLAGS = -Wall -Wextra -Werror
RM     = rm -f

SEP = ================================================================================================================

# ========================= DIRECTORIOS Y ARCHIVOS =========================== #

OBJ_DIR = obj

SRCS = ft_atoi.c      ft_bzero.c      ft_calloc.c       ft_isalnum.c    ft_isalpha.c \
       ft_isascii.c   ft_isdigit.c    ft_isprint.c      ft_itoa.c       ft_memchr.c \
       ft_memcmp.c    ft_memcpy.c     ft_memmove.c      ft_memset.c     ft_putchar_fd.c \
       ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c    ft_split.c      ft_strcmp.c \
       ft_strdup.c    ft_striteri.c   ft_strjoin.c      ft_strlcat.c    ft_strlcpy.c \
       ft_strlen.c    ft_strmapi.c    ft_strncmp.c      ft_strnstr.c    ft_strrchr.c \
       ft_strtrim.c   ft_substr.c	  ft_strstr.c       ft_tolower.c  	ft_toupper.c \
	   ft_strempty.c  ft_isspace.c	  ft_free_matrix.c  ft_sqrt.c	    ft_lstchr.c


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
	@echo "${YELLOW}Limpiando archivos objeto de libft...${RESET}"
	$(RM) -r $(OBJ_DIR)

fclean: clean
	@echo "${RED}Eliminando la biblioteca $(NAME)...${RESET}"
	$(RM) $(NAME)

re: fclean all