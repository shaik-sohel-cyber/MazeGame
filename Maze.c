#include <stdio.h>
#include <stdlib.h>

#define HEIGHT 10
#define WIDTH 10

// Function prototypes
void printMaze(char maze[HEIGHT][WIDTH], int posY, int posX);

int main() {
    // Maze layout where ' ' is open path, '#' is wall, 'S' is start, and 'F' is finish.
    char maze[HEIGHT][WIDTH] = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', 'S', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', '#'},
        {'#', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', '#'},
        {'#', ' ', '#', '#', '#', ' ', '#', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', '#', '#', '#', '#', '#', '#', ' ', '#'},
        {'#', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', '#', '#', ' ', '#', 'F', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
    };

    int posX = 1, posY = 1; // Starting position
    printMaze(maze, posY, posX);

    printf("\nUse W A S D keys to move (Followed by Enter). 'Q' to quit.\n");

    char move;
    while(1) {
        scanf(" %c", &move); // Space before %c is to clear any newline characters
        switch(move) {
            case 'w':
            case 'W':
                if(maze[posY-1][posX] != '#' && posY > 0) posY--;
                break;
            case 's':
            case 'S':
                if(maze[posY+1][posX] != '#' && posY < HEIGHT - 1) posY++;
                break;
            case 'a':
            case 'A':
                if(maze[posY][posX-1] != '#' && posX > 0) posX--;
                break;
            case 'd':
            case 'D':
                if(maze[posY][posX+1] != '#' && posX < WIDTH - 1) posX++;
                break;
            case 'q':
            case 'Q':
                printf("Quitting game...\n");
                exit(0);
            default:
                printf("Invalid move! Use W A S D keys to move, 'Q' to quit.\n");
        }

        if(maze[posY][posX] == 'F') {
            printf("Congratulations! You've reached the finish!\n");
            break;
        }

        system("clear");  // for Unix/Linux - use system("cls"); for Windows
        printMaze(maze, posY, posX);
    }

    return 0;
}

void printMaze(char maze[HEIGHT][WIDTH], int posY, int posX) {
    for(int y = 0; y < HEIGHT; y++) {
        for(int x = 0; x < WIDTH; x++) {
            if(y==posY && x==posX)
                printf("P "); // P represents the player
            else
                printf("%c ", maze[y][x]);
        }
        printf("\n");
    }
}
