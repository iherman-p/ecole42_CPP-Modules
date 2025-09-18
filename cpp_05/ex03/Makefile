NAME = test

SRC = main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp

OBJ = $(SRC:.cpp=.o)

FLAGS= -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	@c++ $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	@c++ -c $(FLAGS) -o $@ $<

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: re clean fclean all