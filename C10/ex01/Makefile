CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_cat.c
OBJ = $(SRC:.c=.o)
BIN = ft_cat

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $^ -o $@

$(OBJ):
	$(CC) $(CFLAGS) -c $(SRC) -o $@

fclean: clean
	$(RM) $(BIN)

clean:
	$(RM) $(OBJS)

.PHONY: all clean fclean