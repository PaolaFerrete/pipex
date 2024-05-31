# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paola <paola@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/31 13:21:48 by paola             #+#    #+#              #
#    Updated: 2024/05/31 13:25:45 by paola            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

# compilation and flag
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Directories
SRC_DIR = ./src
OBJ_DIR = ./obj
INCLUDE = ./include

# files sources and objects
SRC_FILES = free_error.c \
			process.c

OBJ_FILES = $(addprefix $(OBJ_DIR)/,$(SRC_FILES:.c=.o))

# Libft files
LIBFT_DIR = ./libft
LIBFT_LIB = $(LIBFT_DIR)/lib
LIBFT = libft.a

# Executable
MAIN_DIR = ./prog

all: $(NAME)

$(NAME): $(OBJ_FILES) $(LIBFT_LIB)/$(LIBFT)
	$(CC) $(CFLAGS) $(MAIN_DIR)/*.c $(OBJ_FILES) -I $(INCLUDE) -o $@ -L $(LIBFT_LIB) -lft

$(LIBFT_LIB)/$(LIBFT): $(LIBFT_DIR)
	@echo "\033[33m----Compiling lib----"
	@make -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)/*.o
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) fclean
	@echo "\n\033[31mDeleting \n"

re: fclean all

.PHONY: all clean fclean re
