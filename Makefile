# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nromptea <mgras@student.42.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/07 18:34:51 by nromptea          #+#    #+#              #
#    Updated: 2016/03/03 13:06:30 by nromptea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NAME = core.c parse2.c display.c calcul.c line.c
OBJ_NAME = $(SRC_NAME:.c=.o)
LIB_NAME = libft

SRC_PATH = ./src/
OBJ_PATH = ./obj/

LIB_PATH = ./libft/
INC_PATH = ./include/ $(LIB_PATH)

SRC      = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ      = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC      = $(addprefix -I, $(INC_PATH))
LIB      = $(addprefix -L, $(LIB_PATH))

NAME     = fdf
CC       = gcc

CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -lft

all: libft $(NAME)

.PHONY: libft clean fclean re $(NAME)

libft :
	make -C $(LIB_PATH)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) $(INC) $(LDFLAGS) -o $(NAME) -lmlx -framework OpenGL -framework AppKit

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean :
	@$(RM) -v $(OBJ)
	@$(RM) -rv $(OBJ_PATH)

fclean : clean
	@$(RM) -v $(NAME)

re: fclean all
