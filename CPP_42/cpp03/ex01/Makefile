NAME	= claptrap_game

CC		= g++
FLAGS	= -Wall -Wextra -Werror -std=c++98
RM		= rm -rf

# Diretórios dos arquivos fonte e de cabeçalho
SRC_DIR	= .
OBJ_DIR	= obj

# Arquivos fonte e objeto
SRCS	= $(wildcard $(SRC_DIR)/*.cpp)
OBJS	= $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

# Nome dos headers
HEADERS = $(wildcard $(SRC_DIR)/*.hpp)

all: $(NAME)

$(NAME): $(OBJS)
	@printf " - Linkando objetos para o executável $(NAME)...\n"
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	@printf "   - Executável $(NAME) está pronto.\n"

# Compilação dos arquivos de objeto
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS) | $(OBJ_DIR)
	@printf " - Compilando $< para $@...\n"
	@$(CC) $(FLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@$(RM) $(OBJ_DIR)
	@printf "   - Objetos removidos.\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "   - Executável removido.\n"

re: fclean all

.PHONY: all clean fclean re
