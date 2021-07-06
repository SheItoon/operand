##
## EPITECH PROJECT, 2019
## makefile of my hunter
## File description:
## do stuff
##

SRC	+=	

MAIN	+=	source/main.cpp

NAME	+=	operand

OBJ	=	$(SRC:.cpp=.o)	\
		$(MAIN:.cpp=.o)

VERSION	=	-std=c++20

CXXFLAGS=	-Wall -Wextra -Werror -pedantic -g3 $(VERSION)

CPPFLAGS=	-I include/

LDFLAGS	=

all:	$(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(LDFLAGS)

re:	clean all

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -rf $(OBJ) $(NAME)

tests_run:
	@rm -f unit_tests *.gcno *.gcda
	@$(CXX) -o unit_tests tests/*.c $(SRC) -I include/ -g3 --coverage -lcriterion
	@./unit_tests

clean_crit:
	@rm -f unit_tests *.gcno *.gcda

.PHONY:	all re clean fclean tests_run clean_crit
