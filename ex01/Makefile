# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fasaravi <fasaravi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/23 18:02:51 by fasaravi          #+#    #+#              #
#    Updated: 2026/09/26 18:10:04 by fasaravi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	phonebook

CXX			=	c++ -g3
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

INC			=	libft.hpp Contact.hpp PhoneBook.hpp

SRC			=	ft_str_isdigits.cpp ft_str_iszero.cpp \
				ft_strtrim.cpp ft_getline.cpp \
				Contact.cpp PhoneBook.cpp \
				main.cpp

OBJ			=	$(SRC:.cpp=.o)

all : $(INC) $(NAME)

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

test : fclean
	clear
	$(MAKE) all
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

.PHONY : all clean fclean re test