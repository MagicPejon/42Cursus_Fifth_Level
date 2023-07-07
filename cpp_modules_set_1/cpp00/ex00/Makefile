# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/04 16:17:02 by amalbrei          #+#    #+#              #
#    Updated: 2023/07/06 19:45:25 by amalbrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone
GPP = g++
CPPFLAGS = -Werror -Wall -Wextra -std=c++98
RM = rm -rf
SRC = MegaPhone.cpp
OBJ = $(SRC:%.cpp=%.o)

%.o: %.cpp
	$(GPP) $(CPPFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(GPP) $(CPPFLAGS) $(OBJ) -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	

re: fclean all

.PHONY: all clean fclean re