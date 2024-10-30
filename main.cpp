#include <iostream>
#include <conio.h>  // For _getch()
#include <windows.h> // For Sleep()

using namespace std;

// Constants for the game grid and frame dimensions
const int GRID_WIDTH = 20;
const int GRID_HEIGHT = 20;
const char FRAME_CHAR = '@';
const string GAME_NAME = "The Tile Game";

// Character representing the player
const char PLAYER = 'O';

// Player's starting position
int playerX = GRID_WIDTH / 2;
int playerY = GRID_HEIGHT / 2;

// Function to clear the screen (works in Windows)
void clearScreen();

// Function to draw the top frame around the grid
void drawFrame(string text); 

// Function to display the game grid with a frame
// needs drawFrame to draw top and bottom frames
// adds the frame on the sides
void drawGrid();

// Function to update player position based on key press
void updatePlayerPosition(char input);

int main() {
    char input;

    while (true) {
        clearScreen();
        drawGrid();

        // Get the arrow key input without waiting for Enter
        input = _getch();
        if (input == 27) break; // Press 'ESC' to quit

        // _getch() returns two values for arrow keys, so get the second one
        if (input == 0 || input == -32) {
            input = _getch();
            updatePlayerPosition(input);
        }

        Sleep(100); // Control game speed
    }

    cout << "Thanks for playing!" << endl;
    return 0;
}

void clearScreen() {
    system("CLS");
}

void drawFrame(string text) {

    // Top border with a centered title
    string title = ("| " + text + " |");

    int frameWidth = GRID_WIDTH + 2;  // Adding 2 for the frame on each side
    int padding = (frameWidth - title.length()) / 2;
    
    cout << string(frameWidth, FRAME_CHAR) << endl;
    cout << string(padding, FRAME_CHAR) << title << string(padding, FRAME_CHAR) << endl;
    cout << string(frameWidth, FRAME_CHAR) << endl;
}

void drawGrid() {

    drawFrame(GAME_NAME); // Draw the top part of the frame

    for (int y = 0; y < GRID_HEIGHT; ++y) {

        cout << FRAME_CHAR; // Left border

        for (int x = 0; x < GRID_WIDTH; ++x) {
            if (x == playerX && y == playerY) {
                cout << PLAYER; // Draw the player
            } else {
                cout << '.';    // Draw empty tile
            }
        }
        cout << FRAME_CHAR << endl; // Right border
    }

    // Bottom border with "Escape to quit" message
    drawFrame("Press ESC to quit.");
}

void updatePlayerPosition(char input) {
    switch (input) {
        case 72: // Up arrow
            if (playerY > 0) playerY--;
            break;
        case 80: // Down arrow
            if (playerY < GRID_HEIGHT - 1) playerY++;
            break;
        case 75: // Left arrow
            if (playerX > 0) playerX--;
            break;
        case 77: // Right arrow
            if (playerX < GRID_WIDTH - 1) playerX++;
            break;
    }
}