CC = cc
CFLAGS = -Wall -Wextra -Werror -std=c11

TARGET =  main
TARGET_C = $(TARGET:=.c)

DEPS = header.h utils.c
all: $(TARGET)

$(TARGET): $(TARGET_C) $(DEPS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(TARGET)

fclean: clean

re: fclean all

.PHONY: all clean fclean re run
