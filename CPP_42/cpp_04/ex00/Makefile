NAME    = ex00

CC      = c++
FLAGS   = -Wall -Wextra -Werror -std=c++98
RM      = rm -rf

# Colors:
GREEN       = \033[92;5;118m
YELLOW      = \033[93;5;226m
GRAY        = \033[33;2;37m
RESET       = \033[0m
CURSIVE     = \033[3m

SRC     = main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp
OBJ     = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@printf "$(CURSIVE)$(GRAY)   - Compiling $(NAME)... $(RESET)\n"
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@printf "$(GREEN)    - Executable ready.$(RESET)\n"

clean:
	@$(RM) $(OBJ)
	@printf "$(YELLOW)    - Object files removed.$(RESET)\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "$(YELLOW)    - Executable removed.$(RESET)\n"

re: fclean all

.PHONY: all clean re fclean