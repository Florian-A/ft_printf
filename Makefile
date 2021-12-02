# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/08 11:45:53 by f██████           #+#    #+#              #
#    Updated: 2021/12/02 17:32:10 by f██████          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

LIB	= $(addprefix ./lib/, \
ft_putnbr_fd.c \
ft_putunbr_fd.c \
ft_strchr.c \
ft_putchar_fd.c \
ft_toupper.c \
ft_calloc.c \
ft_memset.c \
)

SRC	= $(addprefix ./sources/, \
putp_fd.c \
puts_fd.c \
putc_fd.c \
putdi_fd.c \
putu_fd.c \
putx1_fd.c \
putx2_fd.c \
ull_to_hex.c \
i_to_hex.c \
ft_printf.c \
)

CC = gcc
FLAGS = -Wall -Wextra -Werror
AR = ar
INC_DIR	= ./includes
OUT	= libftprintf.a
HEADER_FILE	= $(INC_DIR)/ft_printf.h
LIB_OBJS = $(LIB:.c=.o)
SRC_OBJS = $(SRC:.c=.o)

all: $(OUT)

$(NAME) : $(LIB_OBJS) $(SRC_OBJS) $(AR) $(NAME) $(LIB_OBJS) $(SRC_OBJS) ranlib $(NAME)

$(OUT) : $(LIB_OBJS) $(SRC_OBJS)
	$(AR) -rcs $(OUT) $(LIB_OBJS) $(SRC_OBJS)

%.o: %.c $(HEADER_FILE)
	$(CC) $(FLAGS) -c $< -o $@  -I $(INC_DIR) 

clean:
	rm -f $(LIB_OBJS) $(SRC_OBJS)

fclean : clean
	rm -f $(OUT)

re : fclean all

.PHONY: all clean fclean re