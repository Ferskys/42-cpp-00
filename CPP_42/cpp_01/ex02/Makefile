# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/17 12:55:28 by fsuomins          #+#    #+#              #
#    Updated: 2024/05/17 12:56:46 by fsuomins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = HI_THIS_IS_BRAIN
CC = g++
FLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

OBDIR = .oFiles

FILES = main

SRCS = $(addsuffix .cpp, $(FILES))
OBJDIRS = $(addprefix $(OBDIR)/, $(FILES))
OBJ = $(addprefix $(OBJDIRS)/, $(FILES:=.o))

GREEN = \e[92;5;118m
YELLOW = \e[93;5;226m
GRAY = \e[33;2;37m
RESET = \e[0m
CURSIVE = \e[33;3m

all: $(NAME)

$(NAME): $(OBJ)
	@printf "$(CURSIVE)$(GRAY)    - Compiling $(NAME)... $(RESET)\n"
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@printf "$(GREEN)- Executable ready.\n$(RESET)"

$(OBJDIRS)/%.o: %.cpp
	@mkdir -p $(OBJDIRS)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@$(RM) $(OBDIR)
	@printf "$(YELLOW)    - Object files removed.$(RESET)\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "$(YELLOW)    - Executable removed.$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re