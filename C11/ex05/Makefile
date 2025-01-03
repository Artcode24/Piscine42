CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = do_op.c utils.c utils_2.c operations.c
HEADERS = utils.h utils_2.h operations.h
OBJ = $(SRC:.c=.o)
BIN = do_op

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $^ -o $@

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

fclean: clean
	$(RM) $(BIN)

clean:
	$(RM) $(OBJ)

.PHONY: all clean fclean