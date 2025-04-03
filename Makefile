CC = gcc
CFLAGS = -Wall -I. -Ibook -Iuser -Icommon -Ibook/bookMenu -Ibook/bookAdd -Ibook/bookDelete -Ibook/bookUpdate \
         -Ibook/bookDisplay -Ibook/bookSearch -Ibook/bookStats -Ibook/bookBorrow -Ibook/bookFile \
         -Iuser/userAuth -Iuser/userRegister -Iuser/userFile

SRC = main.c \
      book/bookMenu/book_menu.c book/bookAdd/book_add.c book/bookDelete/book_delete.c book/bookUpdate/book_update.c \
      book/bookDisplay/book_display.c book/bookSearch/book_search.c book/bookStats/book_stats.c book/bookBorrow/book_borrow.c \
      book/bookFile/book_file.c \
      user/userAuth/user_auth.c user/userRegister/user_register.c user/userFile/user_file.c \
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