# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/12 19:20:00 by nmota-bu          #+#    #+#              #
#    Updated: 2022/07/20 18:10:35 by nmota-bu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = getnextline.a
INCLUDES = inc
SRC_DIR = src/
OBJ_DIR = obj/

# Compilate

CC= gcc
CFLAGS = -Wall -Wextra -Werror -g3
AR = ar rcs
RM = rm -f

# Colors
GREEN=\033[0;32m
BLUE=\033[0;34m
ORANGE=\033[38;5;214m
RED=\033[0;31m
YELLOW = \033[0;33m
WHITE= \033[0;37m

#Sources

UTILS_DIR = utils/
UTILS_FILES = ft_memcpy ft_strjoin ft_strlen ft_strdup ft_strchr

SRC_FILES = get_next_line
SRC_FILES += $(addprefix $(UTILS_DIR), $(UTILS_FILES))

SRCS = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

#Rules

all: DIR $(NAME)

$(NAME) : $(OBJS)
			@$(AR) $(NAME) $(OBJS)
			@echo "$(GREEN)\n ✓ Creado $(NAME)\n$(WHITE)"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(INCLUDES)/get_next_line.h
			@echo "$(ORANGE) Compilando  ➟  $(BLUE)$< $(WHITE)"
			@$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

DIR:
			@mkdir -p $(OBJ_DIR)
			@mkdir -p $(OBJ_DIR)$(UTILS_DIR)

clean : 
			echo $(OBJS)
			@$(RM) -r $(OBJ_DIR)
			@echo "$(RED)\n ✗ get_next_line borrados.‼️\n$(WHITE)";

fclean : clean
			@$(RM) $(NAME)

			@echo "$(YELLOW) Todo Super limpito...✌🏼$(WHITE)"

re: fclean all
			@echo "$(YELLOW) Borrado todo y recompilado...✌🏼$(WHITE)"

norm:
			@norminette $(SRCS) $(INCLUDES) | grep -v Norme -B1 || true

# Non-file targets
.PHONY: all clean fclean re norm
