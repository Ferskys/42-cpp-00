NAME    = fragtrap

CC      = g++
FLAGS   = -Wall -Wextra -Werror -std=c++98
RM      = rm -rf

SRCS    = ClapTrap.cpp FragTrap.cpp main.cpp
OBJS    = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@printf " - Compiling objects for $(NAME)...\n"
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)
	@printf " - Executable ready.\n"

clean:
	@$(RM) $(OBJS)
	@printf " - Objects removed.\n"

fclean: clean
	@$(RM) $(NAME)
	@printf " - Executable removed.\n"

re: fclean all

.PHONY: all clean fclean re
