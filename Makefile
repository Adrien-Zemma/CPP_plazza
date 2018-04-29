##
## EPITECH PROJECT, 2018
## plazza
## File description:
## Makefile
##

NAME	= plazza

CC	= g++

RM	= rm -f

SRCS	= ./src/operateurOverload.cpp \
	  ./src/plazza.cpp \
	  ./src/main.cpp \
	  ./src/process.cpp \
	  ./src/transport.cpp \
	  ./test/client.cpp \
	  ./test/serveur.cpp 

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I ./inc
CPPFLAGS += -W -Wall -Wextra
LDFLAGS = 

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
