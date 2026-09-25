# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fasaravi <fasaravi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/23 18:02:48 by fasaravi          #+#    #+#              #
#    Updated: 2026/09/26 00:14:07 by fasaravi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	megaphone

CXX			=	c++
CXXFLAGS		=	-Wall -Wextra -Werror -std=c++98

SRC			=	megaphone.cpp
OBJ			=	$(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $< 

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean
	$(MAKE) all

test : re
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) "shhhhh... I think the students are asleep..."
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) Damnit " ! " "Sorry students, I thought this thing was off."
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

.PHONY : all clean fclean re test