CC = gcc
CFLAGS = -Wall -std=c11
LIBS = -lsqlite3

OBJS = main.o db.o user.o

all: grades

grades: $(OBJS)
	$(CC) $(CFLAGS) -o grades $(OBJS) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	del /Q *.o grades.exe
