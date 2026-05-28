# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nadeluge <nadeluge@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 16:36:10 by aamphima          #+#    #+#              #
#    Updated: 2025/11/27 15:19:17 by nadeluge         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
NAME = libft.a
SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_strcpy.c ft_strlcat.c \

BSRC = ft_lstadd_front_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstaddback_bonus.c  ft_lstmap_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstdelone_bonus.c \

GNL_SRC = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \

# PRINTF_SRC = printf/printf_useful.c printf/ft_printf.c \

OBJ = $(SRC:.c=.o)
BOBJ = $(BSRC:.c=.o)
GNL_OBJ = $(GNL_SRC:.c=.o)
PRINTF_OBJ = $(PRINTF_SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ) $(PRINTF_OBJ) $(GNL_OBJ)
	ar rcs $(NAME) $(OBJ) $(PRINTF_OBJ) $(GNL_OBJ)

bonus: $(BOBJ)
	ar rcs $(NAME) $(BOBJ)

gnl: $(GNL_OBJ)
	ar rcs $(NAME) $(GNL_OBJ)

printf: $(PRINTF_OBJ)
	ar rcs $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BOBJ) $(GNL_OBJ) $(PRINTF_OBJ)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY: all bonus clean fclean re
