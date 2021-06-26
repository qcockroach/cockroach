SRCS=cockroach.c
OBJS=cockroach.o

LIB_LDFLAGS = $(LDFLAGS) -Wl,-soname,$(LIB_FILENAME) -lext2fs

cockroach: clean $(OBJS)
	$(CC) -Wall -s cockroach.o -o cockroach $(LIB_LDFLAGS)

%.o: %.c
	$(CC) -c $< -o $@

clean:
	rm -rf cockroach
