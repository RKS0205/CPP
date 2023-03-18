SRC_FILES= megaphone.cpp
OBJ=$(SRC_FILES:.cpp=.o)
CC = c++
FLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic-errors
NAME=megaphone

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
