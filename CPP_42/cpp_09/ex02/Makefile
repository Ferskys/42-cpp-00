NAME        = PmergeMe
CC          = c++
CFLAGS      = -Wall -Wextra -Werror -std=c++98
RM          = rm -rf

OBDIR       = .oFiles
FILES       = main PmergeMe

SRC         = $(FILES:=.cpp)
OBJ         = $(addprefix $(OBDIR)/, $(FILES:=.o))

# Cores
GREEN       = \033[92;5;118m
YELLOW      = \033[93;5;226m
GRAY        = \033[33;2;37m
RESET       = \033[0m
CURSIVE     = \033[3m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(CURSIVE)$(GRAY)    - Compilando $(NAME)... $(RESET)"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)- Executável pronto.$(RESET)"

$(OBDIR)/%.o: %.cpp
	@mkdir -p $(OBDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBDIR)
	@echo "$(YELLOW)    - Arquivos objeto removidos.$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(YELLOW)    - Executável removido.$(RESET)"

re: fclean all

.PHONY: all clean fclean re