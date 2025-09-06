# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsadikaj <lsadikaj@student.42lausanne.ch>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/03 15:33:34 by lsadikaj          #+#    #+#              #
#    Updated: 2025/09/04 12:17:07 by lsadikaj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables de configuration
GCC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = phonebook
SRCS = main.cpp Phonebook.cpp Contact.cpp
OBJS = $(SRCS:.cpp=.o)

# Règle par défaut
all: $(NAME)

$(NAME): $(OBJS)
	$(GCC) $(CFLAGS) $(OBJS) -o $(NAME)

# Règle générique pour créer les fichiers objets
%.o: %.cpp
	$(GCC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re