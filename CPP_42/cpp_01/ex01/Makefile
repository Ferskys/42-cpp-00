# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/17 12:32:01 by fsuomins          #+#    #+#              #
#    Updated: 2024/05/17 12:46:27 by fsuomins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = moar_brainz

CC          = c++
FLAGS       = -Wall -Wextra -Werror -std=c++98
RM          = rm -rf

OBDIR       = .oFiles

FILES       = main Zombie zombieHorde

SRC         = $(FILES:=.cpp)
OBJ         = $(addprefix $(OBDIR)/, $(FILES:=.o))

GREEN       = \e[92;5;118m
YELLOW      = \e[93;5;226m
GRAY        = \e[33;2;37m
RESET       = \e[0m
CURSIVE     = \e[33;3m

all: $(NAME)

$(NAME): $(OBJ)
	@printf "$(CURSIVE)$(GRAY)    - Compiling $(NAME)... $(RESET)\n"
	@$(CC) $(OBJ) -o $(NAME)
	@printf "$(GREEN)- Executable ready.\n$(RESET)"

$(OBDIR)/%.o: %.cpp
	@mkdir -p $(OBDIR)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@$(RM) -rf $(OBDIR)
	@printf "$(YELLOW)    - Object files removed.$(RESET)\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "$(YELLOW)    - Executable removed.$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re