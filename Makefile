# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tokrandr <tokrandr@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/12 15:47:39 by frajaona          #+#    #+#              #
#    Updated: 2025/05/02 10:16:45 by tokrandr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN= 	$(shell tput -Txterm setaf 2)
BLUE=	$(shell tput -Txterm setaf 6)
END= 	$(shell tput -Txterm sgr0)

NAME = cub3D

LFT = ./libft
LFT_A = $(LFT)/libft.a

MLX = ./minilibx-linux
MLX_A = $(MLX)/libmlx.a

PF = ./ft_printf
PF_A = $(PF)/libftprintf.a

GNL_DIR = ./gnl

V_OBJ = ./obj

DIR_SRC = ./src
SRC_UTILS = $(DIR_SRC)/utils
SRC_INPUTS = $(DIR_SRC)/inputs
SRC_INITS = $(DIR_SRC)/inits
SRC_DESTROY = $(DIR_SRC)/destroys
SRC_KEYBORD = $(DIR_SRC)/keybord
SRC_SYSTEM = $(DIR_SRC)/system
SRC_FILE = $(DIR_SRC)/file


SRC =	$(GNL_DIR)/get_next_line_utils.c $(GNL_DIR)/get_next_line.c \
		$(SRC_UTILS)/setting_utils.c $(SRC_UTILS)/action_utils.c \
		$(SRC_UTILS)/utils_funct.c $(SRC_UTILS)/raycast_utils.c $(SRC_UTILS)/ray_wall_distance.c \
		$(SRC_INPUTS)/checker.c \
		$(SRC_INITS)/init_object.c $(SRC_INITS)/inits_cube.c \
		$(SRC_DESTROY)/destroy.c $(SRC_DESTROY)/destroy_obj.c $(SRC_DESTROY)/destroy_obj2.c\
		$(SRC_KEYBORD)/key.c \
		$(SRC_SYSTEM)/window.c \
		$(SRC_SYSTEM)/textur.c $(SRC_SYSTEM)/raycast.c $(SRC_SYSTEM)/data.c \
		$(SRC_SYSTEM)/draw.c $(SRC_SYSTEM)/action.c \
		$(SRC_FILE)/get_map.c \
		$(SRC_FILE)/parse_map.c \
		$(SRC_FILE)/init_file.c \
		$(SRC_FILE)/check_map.c \
		$(SRC_FILE)/check_error2.c \
		$(SRC_FILE)/check_map2.c \
		$(SRC_FILE)/check_path.c \
		$(SRC_FILE)/check_error.c \
		$(SRC_FILE)/manage_file.c \
		$(SRC_FILE)/get_map_extension.c \
		$(SRC_FILE)/list_add.c \
		$(DIR_SRC)/main_extension.c \
		$(DIR_SRC)/main.c \

OBJS = $(patsubst $(DIR_SRC)/%.c, $(V_OBJ)/%.o, $(filter $(DIR_SRC)/%, $(SRC))) \
       $(patsubst $(GNL_DIR)/%.c, $(V_OBJ)/%.o, $(filter $(GNL_DIR)/%, $(SRC)))

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

INC = -I $(DIR_SRC)/includs  -I $(LFT)   -I$(PF)  -I $(MLX)
MLXF = -lXext -lX11 -lm

RMF = rm -rf
RM = rm -f


OBJ_SUBDIRS = $(sort $(dir $(OBJS)))

all: $(NAME)

$(V_OBJ):
	@mkdir -p $(V_OBJ)

$(OBJ_SUBDIRS): | $(V_OBJ)
	@mkdir -p $@

$(V_OBJ)/%.o: $(DIR_SRC)/%.c | $(OBJ_SUBDIRS)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(V_OBJ)/%.o: $(GNL_DIR)/%.c | $(OBJ_SUBDIRS)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@


$(LFT_A):
	make -C $(LFT)


$(PF_A):
	make -C $(PF)

$(MLX_A):
	make -C $(MLX)
	

$(NAME):$(OBJS) $(LFT_A) $(PF_A) $(MLX_A)
	$(CC) $(CFLAGS) $(OBJS) $(LFT_A) $(PF_A) $(MLX_A) $(MLXF) -o $(NAME)
	@echo
	@echo "$(GREEN)Executable created $(END)"
	@echo

clean:
	@if [ -d $(V_OBJ) ]; then \
		for file in $(OBJS); do \
			if [ -f $$file ]; then rm -f $$file; fi; \
		done; \
		find $(V_OBJ) -type d -empty -delete; \
	fi
	@make clean -C $(LFT)
	@make clean -C $(PF)
	@echo "$(GREEN)Clean complete$(END)"


fclean: clean
	@if [ -d $(V_OBJ) ]; then \
		$(RMF) $(V_OBJ); \
	fi
	@$(RM) -f $(NAME)
	@make fclean -C $(LFT)
	@make fclean -C $(PF)
	@echo "$(GREEN)Full clean complete$(END)"

re: fclean all
