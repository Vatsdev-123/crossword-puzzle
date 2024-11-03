#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int ROWS = 15;
const int COLS = 15;

void printGrid(char grid[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

bool canPlaceWordHorizontal(char grid[ROWS][COLS], const string& word, int row, int col) {
    // Check if the word fits within the grid boundaries
    if (col + word.length() > COLS) {
        return false;
    }

    // Check for overlapping characters
    for (int i = 0; i < word.length(); i++) {
        if (grid[row][col + i] != '-' && grid[row][col + i] != word[i]) {
            return false;
        }
    }

    return true;
}

// Similar function for vertical placement

bool placeWordHorizontal(char grid[ROWS][COLS], const string& word, int row, int col) {
    // Place the word on the grid
    for (int i = 0; i < word.length(); i++) {
        grid[row][col + i] = word[i];
    }
    return true;
}

// Similar function for vertical placement

bool removeWordHorizontal(char grid[ROWS][COLS], const string& word, int row, int col) {
    // Remove the word from the grid
    for (int i = 0; i < word.length(); i++) {
        grid[row][col + i] = '-';
    }
    return true;
}

// Similar function for vertical removal

bool solveCrossword(char grid[ROWS][COLS], const vector<string>& words, int wordIndex) {
    if (wordIndex == words.size()) {
        return true; // All words placed successfully
    }

    string word = words[wordIndex];
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (canPlaceWordHorizontal(grid, word, row, col)) {
                placeWordHorizontal(grid, word, row, col);
                if (solveCrossword(grid, words, wordIndex + 1)) {
                    return true;
                }
                removeWordHorizontal(grid, word, row, col);
            }

            // Check for vertical placement as well
        }
    }
    return false;
}

int main() {
    char grid[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = '-';
        }
    }

    vector<string> words = {"CAT", "DOG", "RAT", "FOX"};

    if (solveCrossword(grid, words, 0)) {
        printGrid(grid);
    } else {
        cout << "No solution found." << endl;
    }

    return 0;
}