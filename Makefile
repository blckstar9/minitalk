# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/30 16:59:31 by aybelaou          #+#    #+#              #
#    Updated: 2025/03/09 17:58:14 by aybelaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -----------------------------------Colors------------------------------------

ORANGE			= \033[38;2;255;165;0m
BOLD_ORANGE		= \033[1;38;5;214m
BG_YELLOW		= \033[48;5;214m
MAGENTA			= \033[0;35m
BOLD_MAGENTA	= \033[1;35m
RESET			= \033[0m

# ---------------------------------Compilation---------------------------------

NAME_SERVER		= server
NAME_CLIENT		= client
CC				= cc
CFLAGS			= -Werror -Wall -Wextra -I includes
RM				= rm -rf

OBJS_DIR		= objs
SRCS_DIR		= srcs
SRCS_CLIENT		= $(wildcard $(SRCS_DIR)/client.c) $(wildcard $(SRCS_DIR)/client_utils.c)
SRCS_SERVER		= $(wildcard $(SRCS_DIR)/server.c)
OBJS_SERVER		= $(addprefix $(OBJS_DIR)/, $(SRCS_SERVER:.c=.o))
OBJS_CLIENT		= $(addprefix $(OBJS_DIR)/, $(SRCS_CLIENT:.c=.o))

# ---------------------------------Librairies----------------------------------
 
LIBFT			= libft/libft.a

# -----------------------------------Rules-------------------------------------

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJS_SERVER) $(LIBFT)
	@echo "$(ORANGE)Building $(NAME_SERVER)...$(RESET)"
	@$(CC) $(OBJS_SERVER) $(LIBFT) $(CFLAGS) -o $(NAME_SERVER)
	@echo "$(BOLD_ORANGE)$(NAME_SERVER) is ready!$(RESET)"

$(NAME_CLIENT): $(OBJS_CLIENT) $(LIBFT)
	@echo "$(ORANGE)Building $(NAME_CLIENT)...$(RESET)"
	@$(CC) $(OBJS_CLIENT) $(LIBFT) $(CFLAGS) -o $(NAME_CLIENT)
	@echo "$(BOLD_ORANGE)$(NAME_CLIENT) is ready!$(RESET)"

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C libft

fclean: clean
	@echo "$(MAGENTA)Removing the libft...$(RESET)"
	@make fclean -C libft
	@$(RM) $(NAME_SERVER) $(NAME_CLIENT)
	@echo "$(BOLD_MAGENTA)Executables removed!$(RESET)"

clean:
	@echo "$(MAGENTA)Cleaning libft object files...$(RESET)"
	@make clean -C libft
	@$(RM) -r $(OBJS_DIR)
	@echo "$(BOLD_MAGENTA)All object files cleaned!$(RESET)"

re: fclean all
	@echo "$(BG_YELLOW)Cleaned and rebuilt everything!$(RESET)"

.PHONY: all clean fclean re