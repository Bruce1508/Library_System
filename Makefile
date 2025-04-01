CC = gcc
CFLAGS = -Wall

SRC = main.c \
      book/book_menu.c book/book_add.c book/book_delete.c book/book_update.c \
      book/book_display.c book/book_search.c book/book_stats.c book/book_borrow.c \
      user/user_auth.c user/user_register.c user/user_file.c \
      common/common.c

OBJ = $(SRC:.c=.o)
EXEC = library_system

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)