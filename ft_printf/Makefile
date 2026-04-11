# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/12 15:47:39 by frajaona          #+#    #+#              #
#    Updated: 2024/12/29 15:43:05 by frajaona         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

INC = include/ft_printf.h

SRC = ft_check.c ft_printf.c ft_printf_str.c ft_printf_nb.c


COMPILED_FILES := 0
BAR_SIZE := 50
G				= $(RED)
X 				= $(END)

OBJS = ${SRC:.c=.o}

TOTAL_FILES := $(words $(OBJS))

FLAG = -Wall -Wextra -Werror

.c.o:
		@cc ${FLAG} -c $< -o $(<:.c=.o) -I${INC}


${NAME} : ${OBJS}
		@ar rcs $(NAME) $(OBJS)

all : ${NAME}

clean :
	@rm -f *.o

fclean : clean
		@rm -f ${NAME}

re : fclean all
