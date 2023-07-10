# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/09 15:58:46 by amalbrei          #+#    #+#              #
#    Updated: 2023/07/09 16:03:24 by amalbrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = violence
CXX = c++
CXXFLAGS = -Werror -Wall -Wextra -std=c++98
RM = rm -rf
SRC = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
OBJ = $(SRC:%.cpp=%.o)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	

re: fclean all

.PHONY: all clean fclean re