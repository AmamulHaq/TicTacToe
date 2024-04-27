#include <iostream>
//tic tac toe in cpp
//number indexing 
#include <string>
using namespace std;

char value[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char turn = 'X';
int row, col, num;

void display() {
    system("cls");
    cout << "\n\tTIC TAC TOE\n";
    cout << "\tPlayer1=[X]\n\tPlayer2=[O]\n";
    cout << "\t     |     |     \n";
    cout << "\t  " << value[0][0] << "  |  " << value[0][1] << "  |  " << value[0][2] << "  \n";
    cout << "\t_____|_____|_____\n";
    cout << "\t     |     |     \n";
    cout << "\t  " << value[1][0] << "  |  " << value[1][1] << "  |  " << value[1][2] << "  \n";
    cout << "\t_____|_____|_____\n";
    cout << "\t     |     |     \n";
    cout << "\t  " << value[2][0] << "  |  " << value[2][1] << "  |  " << value[2][2] << "  \n";
    cout << "\t     |     |     \n";
    cout << "\n\tTurn of player [" << turn << "]:" << endl;
}

void select() {
    cin >> num;
    switch (num) {
    case 1:
        row = 0;
        col = 0;
        break;
    case 2:
        row = 0;
        col = 1;
        break;
    case 3:
        row = 0;
        col = 2;
        break;
    case 4:
        row = 1;
        col = 0;
        break;
    case 5:
        row = 1;
        col = 1;
        break;
    case 6:
        row = 1;
        col = 2;
        break;
    case 7:
        row = 2;
        col = 0;
        break;
    case 8:
        row = 2;
        col = 1;
        break;
    case 9:
        row = 2;
        col = 2;
        break;
    default:
        cout << "Invalid choice";
        break;
    }
}

bool checkWin() {
    char win;
    for (int i = 0; i < 3; i++) {
        // Check rows
        if (value[i][0] == value[i][1] && value[i][0] == value[i][2]) {
            win = value[i][0]; 
            display();
            cout << "Player " << win << " wins!" << endl;
            return true;
        }
        // Check columns
        if (value[0][i] == value[1][i] && value[0][i] == value[2][i]) {
            win = value[0][i]; 
            display();
            cout << "Player " << win << " wins!" << endl;
            return true;
        }
    }

    // Check diagonals
    if (value[0][0] == value[1][1] && value[0][0] == value[2][2]) {
        win = value[0][0]; 
        display();
        cout << "Player " << win << " wins!" << endl;
        return true;
    }
   // Check diagonals
    if (value[0][2] == value[1][1] && value[0][2] == value[2][0]) {
        win = value[0][2];
		display(); 
        cout << "Player " << win << " wins!" << endl;
        return true;
    }

    return false;
}

bool checkDraw() {
   
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (value[i][j] != 'X' && value[i][j] != 'O') {
                return false; 
            }
        }
    }
    return true; 
}

int main() {
    display();
    int i;
    for (i = 0; i < 9; i++) {
        select();
        if (value[row][col] != 'X' && value[row][col] != 'O') {
            value[row][col] = turn;
            if (checkWin()) {
            
                break;
            } else if (checkDraw()) {
            	display();
                cout << "\nThe game is a draw." << endl;
                break;
            } else {
                turn = (turn == 'X') ? 'O' : 'X';
                display();
            }
        } else {
            cout << "\nInvalid location! Try again." << endl;
            i--;
        }
    }

    return 0;
}
