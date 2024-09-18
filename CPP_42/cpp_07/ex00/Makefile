CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = ex00

SRC = main.cpp
HEADERS = whatever.hpp

all: $(NAME)

$(NAME): $(SRC) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all
