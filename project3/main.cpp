#include <iostream>

using namespace std;

int
    board[9];

int score(int cell1,int cell2,int cell3) {

}

bool playerWins(int playerNum) {

    if (score(0,1,2) == 3 && playerNum == 1)
        return true;
    if (score(0,1,2) == -3 && playerNum == -1)
        return true;

    // copy 7 more times for the other 7 lines

    return false;
}

bool canWin(int playerNum,int &winningSquare) {

    if (score(0,1,2) == 2 && playerNum == 1) {
        if (board[0] == 0)
            winningSquare = 0;
        if (board[1] == 0)
            winningSquare = 1;
        if (board[2] == 0)
            winningSquare = 2;
        return true;
    }
    if (score(0,1,2) == -2 && playerNum == -1)
        return true;

    // copy 7 more times

    return false;
}

char toLetter(int cell) {

    if (cell == 1)
        return 'X';
    else if (cell == -1)
        return 'O';
    else
        return ' ';
}

void printBoard() {

    cout << "   |   |   " << endl;
    cout << ' ' << toLetter(board[0]) << " | " << toLetter(board[1]) << " | "
         << toLetter(board[2]) << ' ' << endl;
    cout << "   |   |   \n"
            "---+---+---\n"
            "   |   |   " << endl;
    cout << ' ' << toLetter(board[3]) << " | " << toLetter(board[4]) << " | "
         << toLetter(board[5]) << ' ' << endl;
    cout << "   |   |   \n"
            "---+---+---\n"
            "   |   |   " << endl;
    cout << ' ' << toLetter(board[6]) << " | " << toLetter(board[7]) << " | "
         << toLetter(board[8]) << ' ' << endl;
    cout << "   |   |   " << endl;
}

int getComputerMove(int computerNum) {
    int
        ws;

    if (canWin(computerNum,ws))
        return ws;
    if (canWin(-computerNum,ws))
        return ws;
    if (board[4] == 0)
        return 4;
    // continue the progression... 0, 2, 6, 8, 1, 3, 5, 7
}

int getHumanMove(int playerNum) {

    // while (true) { ... infinite loop, sort of

        // get move from human... could be row col or could be position #

        // convert input into 0--8

        // if position is valid, return it

        // display error message
    // }
}

int main() {

    printBoard();

    return 0;
}
