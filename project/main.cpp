#include <iostream>
#include "GAME1.h"
#include "GAME2.h"
#include "GAME4.h"
#include "GAME5.h"
#include "GAME8.h"
#include "GAME9.h"
#include "tictacG1.h"
#include "tictacG2.h"

using namespace std;
int main() {

    while (true) {
        int choice;
        cout << "MENU:\n"
             << "1) Pyramic Tic-Tac-Toe\n"
             << "2) Four-in-a-row\n"
             << "3) 5 x 5 Tic Tac Toe\n"
             << "4) Word Tic-tac-toe\n"
             << "5) Numerical Tic-Tac-Toe\n"
             << "6) Misere Tic Tac Toe\n"
             << "7) Ultimate Tic Tac Toe\n"
             << "8) The SUS\n"
             << "9) Exit\n"
             << "Please enter your choice: ";
        cin >> choice;
        if (choice == 1) {
            cout << "RULES:\n";
            cout << "The first player to get three-in-a-row vertically, horizontally, or diagonally wins\n";
            game1_main();
        }
        else if (choice == 2) {
            cout << "RULES:\n";
            cout << "The first player to get four-in-a-row vertically, horizontally, or diagonally wins.\n";
            game2_main();
        }
        else if (choice == 3) {
            cout << "RULES:\n";
            cout << " Align 3 of your symbols (X or O) in a row, column, or diagonal to score a win.\n";
            tic_main();
        }
        else if (choice == 4) {
            cout << "RULES:\n";
            cout << "The game is won by forming a valid word horizontally, vertically, or diagonally.\n";
            game4_main();
        }
        else if (choice == 5) {
            cout << "RULES:\n";
            cout << "The first player has the odd numbers from 1 to 9, and the second player has the even numbers from 2 to 8. Each number is used only once, and the player who collects three numbers of 15 or more in a vertical, horizontal or diagonal shape wins.\n";
            game5_main();
        }
        else if (choice == 6) {
            cout << "RULES:\n";
            cout<<"Align three symbols (X or O) in a row to win; a full grid without a winner is a draw.\n";
            toe_main();
        }
        else if (choice == 7) {
            cout << "RULES:\n";
            cout << "The first player to win three smaller boards in a row on the main 3x3 grid wins\n";
            game8_main();
        }
        else if (choice == 8) {
            cout << "RULES:\n";
             cout <<"Form <SUS> on a 3x3 grid; the most sequences win after 9 moves.\n";
            game9_main();
        }
        else if (choice == 9) {
            break;
        }
    }
    return 0;
}