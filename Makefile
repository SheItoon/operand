##
## EPITECH PROJECT, 2019
## makefile of my hunter
## File description:
## do stuff
##

SRC	=	source/operand.cpp	\
		source/utils.cpp	\
		source/register.cpp

MAIN	=	source/main.cpp

NAME	=	operand

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

CI:
	> $(foreach SRC, $(SRC), bash CI.sh $(SRC) && ) true
#tests_run:

.PHONY:	all re clean fclean CI#tests_run
