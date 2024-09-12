NAME        = ex02

CC          = c++
FLAGS       = -Wall -Wextra -Werror -std=c++98
RM          = rm -rf

OBDIR       = .oFiles

FILES       = main Bureaucrat AForm ShrubberyCreationForm RobotomyRequestForm PresidentialPardonForm Intern

SRC         = $(FILES:=.cpp)
OBJ         = $(addprefix $(OBDIR)/, $(FILES:=.o))

GREEN       = \033[92;5;118m
YELLOW      = \033[93;5;226m
GRAY        = \033[33;2;37m
RESET       = \033[0m
CURSIVE     = \033[3m

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