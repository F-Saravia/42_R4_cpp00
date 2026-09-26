# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fasaravi <fasaravi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/23 18:02:51 by fasaravi          #+#    #+#              #
#    Updated: 2026/09/26 21:33:53 by fasaravi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	accounts

CXX			=	c++ -g3
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

INC			=	Account.hpp

SRC			=	Account.cpp tests.cpp

OBJ			=	$(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ) 
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o : %.cpp $(INC) 
	$(CXX) $(CXXFLAGS) -o $@ -c $< 

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean
	$(MAKE) all

test : fclean
	clear
	$(MAKE) all
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

.PHONY : all clean fclean re test