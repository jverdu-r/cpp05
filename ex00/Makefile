# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jverdu-r <jverdu-r@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 17:17:30 by jverdu-r          #+#    #+#              #
#    Updated: 2024/11/28 16:28:44 by jverdu-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++

CXXFLAGS = -std=c++98 -Wall -Werror -Wextra

SRC = src/Bureaucrat.cpp \
		src/main.cpp

NAME = Bureaucrat

LDFLAGS = -std=c++98
RM = /bin/rm -rf
OBJ = $(SRC:.cpp=.o)

$(NAME): $(OBJ)
	c++ $(LDFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)
clean:
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re