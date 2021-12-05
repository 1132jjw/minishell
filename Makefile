# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeujeon <jeujeon@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/19 14:19:40 by jeunjeon          #+#    #+#              #
#    Updated: 2021/12/05 21:22:49 by jeujeon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	minishell
CC					=	gcc
CFLAGS				=	-fsanitize=address # -Wall -Wextra -Werror

SRCS_NAME			=	main.c\
						ft_chdir.c\
						ft_echo.c\
						ft_exit.c\
						ft_pwd.c\
						parsing.c\
						
SRCS_PATH			=	./srcs
SRCS				=	$(addprefix $(SRCS_PATH)/, $(SRCS_NAME))

OBJS_NAME			=	$(SRCS_NAME:.c=.o)
OBJS_PATH			=	./objs
OBJS				=	$(addprefix $(OBJS_PATH)/, $(OBJS_NAME))

INC_PATH			=	./inc

LIBFT_NAME			=	ft
LIBFT_PATH			=	./libft

$(NAME)				:	$(OBJS)
						@echo "\n"
						@$(MAKE) -C $(LIBFT_PATH) all
						@echo "\033[0;32mCompiling minishell..."
						@$(CC) $(CFLAGS) $(OBJS) -I$(INC_PATH) -L$(LIBFT_PATH) -l$(LIBFT_NAME) -lreadline -o $@
						@echo "\n\033[0mDone !"

$(OBJS_PATH)/%.o	:	$(SRCS_PATH)/%.c
						@mkdir $(OBJS_PATH) 2> /dev/null || true
						@printf "\033[0;33mGenerating minishell objects... %-33.33s\r" $@
						@$(CC) $(CFLAGS) -I$(INC_PATH) -c $< -o $@

all					:	$(NAME)
						

clean				:
						@echo "\033[0;31mCleaning libft..."
						@$(MAKE) -C $(LIBFT_PATH) clean
						@echo "\nRemoving binaries..."
						@rm -rf $(OBJS)
						@echo "\033[0m"

fclean				:
						@echo "\033[0;31mCleaning libft..."
						@$(MAKE) -C $(LIBFT_PATH) fclean
						@echo "\nDeleting objects..."
						@rm -rf $(OBJS)
						@echo "\nDeleting executable..."
						@rm -rf $(NAME)
						@echo "\033[0m"

re					:	fclean all

.PHONY				:	all clean fclean re
