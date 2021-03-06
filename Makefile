##
## EPITECH PROJECT, 2018
## plazza
## File description:
## Makefile
##

NAME	= plazza

CC	= g++

RM	= rm -f

SRCS	= ./src/Plazza.cpp \
	  ./src/Threadpool.cpp\
	./src/main.cpp

OBJS	= $(SRCS:.cpp=.o)

CXXFLAGS = -I ./inc
CXXFLAGS += -Wall -Wextra -pthread -std=c++14 -g3
LDLIBS = -lpthread
LDFLAGS = 

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(CXXFLAGS) $(OBJS) -o $(NAME) $(LDLIBS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all gui clean_gui clean fclean_gui fclean re
