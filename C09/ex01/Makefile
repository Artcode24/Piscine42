CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes
SRC = $(wildcard srcs/*.c)
OBJDIR = srcs
OBJS = $(patsubst srcs/%.c, $(OBJDIR)/%.o, $(SRC))
HEADERS = includes/ft.h
BIN = libft.a

all: $(BIN)

$(BIN): $(OBJS)
	ar rcs $@ $^

$(OBJDIR)/%.o: srcs/%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

fclean: clean
	$(RM) $(BIN)

clean:
	$(RM) $(OBJS)

re: fclean all

.PHONY: all clean fclean re