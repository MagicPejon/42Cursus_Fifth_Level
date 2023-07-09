# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/09 14:49:55 by amalbrei          #+#    #+#              #
#    Updated: 2023/07/09 14:54:40 by amalbrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = zombie
CXX = c++
CXXFLAGS = -Werror -Wall -Wextra -std=c++98
RM = rm -rf
SRC = main.cpp Zombie.cpp zombieHorde.cpp
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