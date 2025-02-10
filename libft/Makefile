# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/14 18:17:35 by aybelaou          #+#    #+#              #
#    Updated: 2025/01/31 15:53:13 by aybelaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

# source and object folders 
SRC_DIR = src
OBJ_DIR = obj

# headers
INC_DIR = inc
LIBFT_INC = $(INC_DIR)/libft_inc
PRINTF_INC = $(INC_DIR)/printf_inc
GNL_INC = $(INC_DIR)/gnl_inc

# source files
LIBFT_SRC = $(wildcard $(SRC_DIR)/libft_src/*.c)
PRINTF_SRC = $(wildcard $(SRC_DIR)/printf_src/*.c)
GNL_SRC = $(wildcard $(SRC_DIR)/gnl_src/*.c)
SRC = $(LIBFT_SRC) $(PRINTF_SRC) $(GNL_SRC)

# object files
OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

# colors
DEF_COLOR = \033[0;39m
ORANGE = \033[38;5;214m
BLUE = \033[0;94m
BOLD_BLUE = \033[1;94m
BOLD_ORANGE = \033[1;38;5;214m
BG_YELLOW = \033[48;5;214m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(ORANGE)Building the libft...$(DEF_COLOR)"
	@ar rcs $(NAME) $(OBJ)
	@echo "$(BOLD_ORANGE)Libft built.$(DEF_COLOR)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I$(LIBFT_INC) -I$(PRINTF_INC) -I$(GNL_INC) -c $< -o $@

clean:
	@$(RM) -r $(OBJ_DIR)
	@echo "$(BLUE)Object files cleaned!$(DEF_COLOR)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(BOLD_BLUE)Library $(NAME) removed!$(DEF_COLOR)"

re: fclean all
	@echo "$(BG_YELLOW)Cleaned and rebuilt everything!$(DEF_COLOR)"

.PHONY: all clean fclean re