CC = cc
CFLAGS = -Wall -Wextra -Werror -std=c11

TARGET =  main
SRCS = main.c

DEPS = header.h utils.c sort.c
all: $(TARGET)

$(TARGET): $(SRCS) $(DEPS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(TARGET)

fclean: clean

re: fclean all

.PHONY: all clean fclean re run
