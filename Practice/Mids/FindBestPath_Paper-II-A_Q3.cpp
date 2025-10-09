#include <iostream>
#include <climits>
using namespace std;

const int N = 6;
char grid[N][N] = {
    {'H','S','S','X','R','R'},
    {'S','S','S','X','S','R'},
    {'S','R','S','S','S','X'},
    {'S','X','S','X','S','S'},
    {'S','S','S','R','S','X'},
    {'S','X','S','S','S','D'}
};

bool visited[N][N];
int maxHealth = -1;
int bestPathRow[50], bestPathCol[50];
int tempPathRow[50], tempPathCol[50];
int pathLen = 0, bestLen = 0;

// Moves: up, down, left, right
int dRow[] = {-1, 1, 0, 0};
int dCol[] = {0, 0, -1, 1};

void findPath(int r, int c, int health) {
    // If out of bounds or dangerous area
    if (r < 0 || c < 0 || r >= N || c >= N || grid[r][c] == 'X' || visited[r][c])
        return;

    // Health check
    if (health <= 0) return;

    // Mark visited and add to current path
    visited[r][c] = true;
    tempPathRow[pathLen] = r;
    tempPathCol[pathLen] = c;
    pathLen++;

    // If reached destination
    if (grid[r][c] == 'D') {
        if (health > maxHealth) {
            maxHealth = health;
            bestLen = pathLen;
            for (int i = 0; i < pathLen; i++) {
                bestPathRow[i] = tempPathRow[i];
                bestPathCol[i] = tempPathCol[i];
            }
        }
    } 
    else {
        // Lose health if red zone
        int newHealth = health - (grid[r][c] == 'R' ? 10 : 0);

        // Explore all directions
        for (int i = 0; i < 4; i++)
            findPath(r + dRow[i], c + dCol[i], newHealth);
    }

    // Backtrack
    visited[r][c] = false;
    pathLen--;
}

int main() {
    int startR = 0, startC = 0; // H at top-left
    findPath(startR, startC, 100);

    if (maxHealth == -1)
        cout << "No path to D found!\n";
    else {
        cout << "Best path (with max health " << maxHealth << "):\n";
        for (int i = 0; i < bestLen; i++)
            cout << "(" << bestPathRow[i] << "," << bestPathCol[i] << ") ";
        cout << endl;
    }
    return 0;
}
