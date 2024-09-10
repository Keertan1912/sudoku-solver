#include <bits/stdc++.h>
using namespace std;

bool canPlace(vector<vector<char>> &grid, int row, int col, char num) {
    for (int i = 0; i < 9; i++) {
        if (grid[i][col] == num)
            return false;

        if (grid[row][i] == num)
            return false;

        if (grid[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == num)
            return false;
    }
    return true;
}

bool solveGrid(vector<vector<char>> &grid) {
    for (int row = 0; row < grid.size(); row++) {
        for (int col = 0; col < grid[row].size(); col++) {
            if (grid[row][col] == '.') {
                for (char num = '1'; num <= '9'; num++) {
                    if (canPlace(grid, row, col, num)) {
                        grid[row][col] = num;

                        if (solveGrid(grid))
                            return true;
                        else
                            grid[row][col] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main() {
    vector<vector<char>> sudokuGrid(9, vector<char>(9));

    cout << "Enter the Sudoku grid values (use '.' for empty cells):\n";
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> sudokuGrid[i][j];
        }
    }

    solveGrid(sudokuGrid);

    cout << "Solved Sudoku grid:\n";
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << sudokuGrid[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
