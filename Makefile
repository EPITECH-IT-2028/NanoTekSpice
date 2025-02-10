SRC = src/main.cpp \
			src/execution.cpp \

OBJ = $(SRC:.cpp=.o)

NAME = nanotekspice

CPPFLAGS = -W -Wall -Wextra  -std=c++20 -I./include

CRITF = --coverage -lcriterion

CC = g++

all: $(NAME) clean

$(NAME): $(OBJ)
	$(CC) -lncurses -o $(NAME) $(OBJ)

clean:
	find . -name "*~" -delete
	rm -f *.gcno
	rm -f *.gcda

fclean: clean
	rm -f $(OBJ)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
