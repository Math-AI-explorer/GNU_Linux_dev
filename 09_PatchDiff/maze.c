#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateMaze(char pass, char wall, int size) {
    srand((unsigned int)time(NULL));

    // Allocate memory for the maze
    char **maze = (char **)malloc(size * sizeof(char *));
    for (int i = 0; i < size; ++i) {
        maze[i] = (char *)malloc(size * 2 + 1);
    }

    // Initialize the maze with walls
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size * 2 + 1; ++j) {
            maze[i][j] = wall;
        }
    }

    // Create paths
    for (int i = 1; i < size; i += 2) {
        for (int j = 1; j < size * 2; j += 2) {
            maze[i][j] = pass;
        }
    }

    // Print the maze
    for (int i = 0; i < size; ++i) {
        printf("%s\n", maze[i]);
    }

    // Free memory
    for (int i = 0; i < size; ++i) {
        free(maze[i]);
    }
    free(maze);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s pass wall size\n", argv[0]);
        return 1;
    }

    char pass = argv[1][0];
    char wall = argv[1][1];
    int size = atoi(argv[3]);

    generateMaze(pass, wall, size);

    return 0;
}
