CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

all: ft_lib1.o ft_lib2.o rush02.o init.o dictionary.o \
	print.o helper.o engine.o validate.o
	$(CC) $(CFLAGS) -o rush-02 ft_lib1.o ft_lib2.o rush02.o init.o \
		dictionary.o helper.o engine.o print.o validate.o

ft_lib1.o: lib/ft_lib1.c lib/ft_lib.h
	$(CC) lib/ft_lib1.c -o ft_lib1.o -c $(CFLAGS)

ft_lib2.o: lib/ft_lib2.c lib/ft_lib.h
	$(CC) lib/ft_lib2.c -o ft_lib2.o -c $(CFLAGS)

rush02.o: rush02.c rush02.h lib/ft_lib.h
	$(CC) rush02.c -o rush02.o -c $(CFLAGS)


init.o: init.c rush02.h lib/ft_lib.h
	$(CC) init.c -o init.o -c $(CFLAGS)


dictionary.o: dictionary.c rush02.h lib/ft_lib.h
	$(CC) dictionary.c -o dictionary.o -c $(CFLAGS)


helper.o: helper.c rush02.h lib/ft_lib.h
	$(CC) helper.c -o helper.o -c $(CFLAGS)

engine.o: engine.c rush02.h lib/ft_lib.h
	$(CC) engine.c -o engine.o -c $(CFLAGS)

print.o: print.c rush02.h
	$(CC) print.c -o print.o -c $(CFLAGS)

validate.o: validate.c rush02.h
	$(CC) validate.c -o validate.o -c $(CFLAGS)

clean:
	$(RM) *.o

fclean:
	make clean
	$(RM) rush-02

re:
	make fclean
	make all

