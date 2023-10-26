#include <iostream>

using namespace std;

int
    board[9];

int score(int cell1,int cell2,int cell3) {

}

bool playerWins(int playerNum) {

}

bool canWin(int playerNum,int &winningSquare) {

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

}

int getHumanMove(int playerNum) {

}

int main() {

    printBoard();

    return 0;
}
