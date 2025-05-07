CC = cc
CFLAGS = -Wall -Wextra -Werror -std=c11

TARGET =  push_swap
SRCS = utils.c sort.c array.c ops.c butterfly.c split.c ft_utils.c normilize.c
DEPS = header.h

all: $(TARGET)

$(TARGET): $(SRCS) $(DEPS) main.c
	$(CC) $(CFLAGS) $(SRCS) main.c -o push_swap
	
checker: $(SRCS) $(DEPS) checker.c
	$(CC) $(CFLAGS) $(SRCS) checker.c -o checker

clean:
	rm -f *.o

fclean: clean
	rm -f $(TARGET)
	rm -f checker

re: fclean all

.PHONY: all clean fclean re run
