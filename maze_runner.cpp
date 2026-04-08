#include <iostream>
using namespace std;

// Function to check if treasure is found
// Bool is used for true and false
bool IfTreasureFound(int row, int col, int value)
{
    int r = value / 10;
    int c = value % 10;
    return (r == row && c == col);
}

// Function for next position
// Void because we are not returning anything
void ForNextPosition(int value, int& nextRow, int& nextCol)
{
    nextRow = value / 10;
    nextCol = value % 10;
}

int main()
{
    cout << "Qunoot Ahmad (049) \t Wajeeha Fatima (006) \t Abdul Rehman (034)";

    int maze[5][5] = {
        {34, 21, 32, 41, 25},
        {14, 42, 43, 14, 31},
        {54, 45, 52, 42, 23},
        {33, 15, 51, 31, 35},
        {21, 52, 33, 13, 23}
    };

    bool visited[5][5] = { false };

    int row;
    int col;

    cout << "\n\nMaze Runner Treasure Hunt" << endl;

    // while loop will stop when the condition will be true
    while (true)
    {
        cout << "\n Enter row (1-5): ";
        cin >> row;
        cout << "Enter column (1-5): ";
        cin >> col;

        if (row < 1 || row > 5 || col < 1 || col > 5)
        {
            cout << "Invalid coordinates! Try again.\n";
            continue;
        }

        if (visited[row - 1][col - 1])
        {
            cout << "You already visited this cell! Loop detected.\n";
            break;
        }

        visited[row - 1][col - 1] = true;
        int value = maze[row - 1][col - 1];

        cout << "Visited (" << row << "," << col << ") -> " << value << endl;

        if (IfTreasureFound(row, col, value))
        {
            cout << "\n Treasure found at (" << row << "," << col << ")\n";
            break;
        }

        int nextRow, nextCol;
        ForNextPosition(value, nextRow, nextCol);
        cout << "Next clue suggests: (" << nextRow << "," << nextCol << ")\n";
    }

    return 0;
}
