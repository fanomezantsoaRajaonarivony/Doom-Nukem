# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/24 11:25:12 by frajaona          #+#    #+#              #
#    Updated: 2024/12/29 15:43:36 by frajaona         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = 	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c\
		ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c\
		ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c\
		ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c\
		ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c\
		ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c\
		ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c\
		ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c\
		ft_putendl_fd.c ft_putnbr_fd.c ft_strcpy.c ft_strncpy.c\
		ft_strcmp.c

COMPILED_FILES := 0
BAR_SIZE := 50
G				= $(RED)
X 				= $(END)

OBJS = ${SRC:.c=.o}

TOTAL_FILES := $(words $(OBJS))

FLAG = -Wall -Wextra -Werror

.c.o:
		@cc ${FLAG} -c $< -o $(<:.c=.o)

${NAME} : ${OBJS}
		@ar rcs $(NAME) $(OBJS)

all : ${NAME}

clean :
	@rm -f *.o

fclean : clean
		@rm -f ${NAME}

re : fclean all
