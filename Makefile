# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/30 16:59:31 by aybelaou          #+#    #+#              #
#    Updated: 2025/02/10 19:28:25 by aybelaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -----------------------------------Colors------------------------------------

ORANGE	= \033[38;2;255;165;0m
BOLD_ORANGE = \033[1;38;5;214m
BG_YELLOW = \033[48;5;214m
MAGENTA = \033[0;35m
BOLD_MAGENTA = \033[1;35m
RESET	= \033[0m

# ---------------------------------Compilation---------------------------------

NAME	= minitalk
CC 		= cc
CFLAGS 	= -Werror -Wall -Wextra -I includes
RM 		= rm -rf

OBJS_DIR = objs
SRCS_DIR = srcs
SRCS 	= $(wildcard $(SRCS_DIR)/*.c)
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

# ---------------------------------Librairies----------------------------------
 
LIBFT = libft/libft.a

# -----------------------------------Rules-------------------------------------

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	@echo "$(ORANGE)Building $(NAME)...$(RESET)"
	@$(CC) $(OBJS) $(LIBFT) $(CFLAGS) -g -o $(NAME)
	@echo "$(BOLD_ORANGE)$(NAME) is ready!$(RESET)"

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@	

$(LIBFT):
	@make -C libft

fclean : clean
	@echo "$(MAGENTA)Removing the libft...$(RESET)"
	@make fclean -C libft
	@$(RM) $(NAME)
	@echo "$(BOLD_MAGENTA)$(NAME) removed!$(RESET)"

clean :
	@echo "$(MAGENTA)Cleaning libft object files...$(RESET)"
	@make clean -C libft
	@$(RM) -r $(OBJS_DIR)
	@$(RM) srcs/*.o
	@echo "$(BOLD_MAGENTA)All object files cleaned!$(RESET)"

re : fclean all
	@echo "$(BG_YELLOW)Cleaned and rebuilt everything!$(DEF_COLOR)"

.PHONY: all clean fclean re