CC = gcc
CFLAGS = -Wall

SRC = maze.c
PATCHES = patch1.diff patch2.diff patch3.diff
TARGETS = maze patch1 patch2 patch3

all: $(TARGETS)

maze: $(SRC)
    $(CC) $(CFLAGS) $< -o $@

patch1: maze $(PATCHES)
    patch maze.c patch1.diff

patch2: maze $(PATCHES)
    patch maze.c patch2.diff

patch3: maze $(PATCHES)
    patch maze.c patch3.diff

run: all
    ./maze
    ./patch1
    ./patch2
    ./patch3

clean:
    rm -f $(TARGETS) *.o
