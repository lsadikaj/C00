# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsadikaj <lsadikaj@student.42lausanne.ch>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/01 17:10:45 by lsadikaj          #+#    #+#              #
#    Updated: 2025/09/01 18:08:47 by lsadikaj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Varibles de configuration
GCC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = megaphone
SRCS = megaphone.cpp
OBJS = $(SRCS:.cpp=.o)

# Regle par defaut
all: $(NAME)

# Creation de l executable a partir des objets
$(NAME): $(OBJS)
	$(GCC) $(CFLAGS) $(OBJS) -o $(NAME)

# Regle generique pour creer les fichiers objets
%.o: %.cpp
	$(GCC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

.PHONY: all clean fclean re
