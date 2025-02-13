SRC = src/main.cpp \
	src/factory.cpp \
	src/parser.cpp \
	src/execution.cpp \
	src/components/Gate.cpp \
	src/components/Gates.cpp \
	src/components/SpecialComponent.cpp \
	src/Execute.cpp \
	src/error.cpp \

OBJ = $(SRC:.cpp=.o)

NAME = nanotekspice

CPPFLAGS = -W -Werror -Wall -Wextra  -std=c++20 -I./include -g

CRITF = --coverage -lcriterion

CC = g++

all: $(NAME) clean

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	find . -name "*~" -delete
	rm -f *.gcno
	rm -f *.gcda

fclean: clean
	rm -f $(OBJ)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
