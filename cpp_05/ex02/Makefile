NAME = test

SRC = main.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp Bureaucrat.cpp AForm.cpp

HEADERS = PresidentialPardonForm.hpp RobotomyRequestForm.hpp ShrubberyCreationForm.hpp Bureaucrat.hpp AForm.hpp

OBJ = $(SRC:.cpp=.o)

FLAGS= -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ) $(HEADERS)
	@c++ $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	@c++ -c $(FLAGS) -o $@ $<

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: re clean fclean all