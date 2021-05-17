SRCS := $(wildcard src/*.c)
OBJS := $(patsubst src/%.c, obj/%.o, $(SRCS))
CFLAGS := -Wall
CC   := gcc
EXE  := cockroach
LIBS := -lssl -lcrypto 

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) $^ -o $@ # -ljson-c # $(LIBS)
	./$@

obj/%.o: src/%.c
	$(CC) -c $< -o $@ $(CFLAGS)


clean:
	rm -rf $(EXE) obj/*

re: clean all

