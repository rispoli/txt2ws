CC=/usr/bin/gcc
CFLAGS=-W -Wall -Wextra -Werror -pedantic -ansi
DEBUG=-D DEBUG

all: txt2ws

txt2ws: txt2ws.c
	$(CC) $(CFLAGS) $< -o $@

txt2ws-debug: txt2ws.c
	$(CC) $(CFLAGS) $(DEBUG) $< -o txt2ws

clean:
	-rm txt2ws
