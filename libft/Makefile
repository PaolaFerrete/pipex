# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paola <paola@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/19 11:55:04 by pferrete          #+#    #+#              #
#    Updated: 2024/02/16 17:47:24 by paola            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#name of the project
NAME=libft.a

#files
SRC = ./src
SRC_FILES = ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_split.c\
			ft_strchr.c \
			ft_strdup.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_lstadd_back.c \
			ft_lstadd_front.c \
			ft_lstnew.c \
			ft_lstsize.c \
			ft_lstclear.c

OBJ = ./obj/
OBJ_FILES = $(addprefix $(OBJ)/,$(SRC_FILES:.c=.o))
INCLUDE = ./include
LIB = ./lib

#Compilation
CC = gcc
CC_FLAGS = -Wall -Wextra -Werror

#AR
AR = @ar
ARFLAGS = rcs

#rules
all: $(LIB)/$(NAME)

$(LIB)/$(NAME): $(OBJ_FILES)
	@mkdir -p $(LIB)
	$(AR) $(ARFLAGS) $@ $^

$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/*.h
	@mkdir -p $(OBJ)
	$(CC) $(CC_FLAGS) -c  $< -o $@

clean:
	rm -rf $(OBJ)/*.o
	rm -rf $(LIB)/$(NAME)

fclean: clean
	rm -rf $(LIB)
	rm -rf $(OBJ)

re: fclean all

.PHONY: all clean fclean re
