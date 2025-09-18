NAME=megaphone

SRC=megaphone.cpp

OBJ=megaphone.o

FLAGS=-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@c++ $(FLAGS) $(OBJ) $(FLAGS) -o $(NAME)

$(OBJ): $(SRC)
	@c++ $(FLAGS) -c $(SRC)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY re clean fclean all