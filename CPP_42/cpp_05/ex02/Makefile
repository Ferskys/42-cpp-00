NAME        = ex02

CC          = c++
FLAGS       = -Wall -Wextra -Werror -std=c++98
RM          = rm -rf

OBDIR       = .oFiles
SHRUBBERY	= Office_shrubbery

FILES       = main Bureaucrat AForm ShrubberyCreationForm RobotomyRequestForm PresidentialPardonForm 

SRC         = $(FILES:=.cpp)
OBJ         = $(addprefix $(OBDIR)/, $(FILES:=.o))

GREEN       = \033[92;5;118m
YELLOW      = \033[93;5;226m
GRAY        = \033[33;2;37m
RESET       = \033[0m
CURSIVE     = \033[3m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(CURSIVE)$(GRAY)    - Compiling $(NAME)... $(RESET)"
	@$(CC) $(OBJ) -o $(NAME)
	@echo "$(GREEN)- Executable ready.$(RESET)"

$(OBDIR)/%.o: %.cpp
	@mkdir -p $(OBDIR)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@$(RM) -rf $(OBDIR) $(SHRUBBERY)
	@echo "$(YELLOW)    - Object files removed.$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(YELLOW)    - Executable removed.$(RESET)"

re: fclean all

.PHONY: all clean fclean re