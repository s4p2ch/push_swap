CC = cc
CFLAGS = -Wall -Wextra -Werror -std=c11

TARGET =  push_swap
SRCS = main.c utils.c sort.c array.c ops.c
DEPS = header.h

all: $(TARGET)

$(TARGET): $(SRCS) $(DEPS)
	$(CC) $(CFLAGS) $(SRCS) -o push_swap

clean:
	rm -f $(TARGET)

fclean: clean

re: fclean all

.PHONY: all clean fclean re run
