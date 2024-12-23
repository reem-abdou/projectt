//
// Created by Reem on 12/17/2024.
//
#include "cmake-build-debug/BoardGame_Classes.h"


#ifndef GAME1_H
#define GAME1_H




template <typename T>
class Game1 : public Board<T>{
    int i,j;
    // bool E;
public:
    Game1(): Board<T>(){
        this->rows=3;
        this->columns=5;
        this->board = new T*[3];
        for (int i = 0; i < 3; ++i) {
            this->board[i] = new T[5]();
        }
    }

    ~Game1(){
        for (int i = 0; i < 3; ++i) {
            delete[] this->board[i];
        }
        delete[] this->board;
    }



    bool update_board(int x, int y, T symbol){
        if(this->board[x][y]!=0){
            cout << "This place is taken, PLEASE TRY AGAIN\n";
            return false;
        }
        this->board[x][y] = symbol;
        i = x;
        j = y;
        return true;
    }

    void display_board(){
        int x = 2;
        for(int i = 0 ; i < 3; i++){
            for(int i = 0 ; i < x; i++){
                cout << "      ";
            }
            for(int j = x ; j < 5-x; j++){
                if(!this->board[i][j]){
                    cout << i << "," <<j;
                }
                else{
                    cout << " " <<this->board[i][j] << " ";
                }
                cout << "   ";
            }
            cout << "\n";
            x--;
        }
    }

    bool is_win(){
        int x = this->i;
        int y = this->j;
        if(x+y==2){
            int n = 0;
            int m = 2;
            for(int i = 1 ; i < 3 ; i++){
                if(this->board[n][m] != this->board[n+i][m-i]){
                    break;
                }
                else if(this->board[n][m] == this->board[n+i][m-i] && this->board[n][m]!=0 && i==2){
                    return true;
                }
                else if(this->board[n][m] == this->board[n+i][m-i] ){
                    continue;
                }
            }
        }
        if(y==2){
            for(int i = 1 ; i < 3 ; i++){
                if(this->board[0][y] != this->board[i][2]){
                    break;
                }
                else if(this->board[0][y] == this->board[i][2] && this->board[0][y] && i==2){
                    return true;
                }
            }
        }
        if (y-x==2){
            int n = 0;
            int m = 2;
            for(int i = 1 ; i < 3 ; i++){
                if(this->board[n][m] != this->board[n+i][m+i]){
                    break;
                }
                else if(this->board[n][m] == this->board[n+i][m+i] && this->board[n][m] && i==2){
                    return true;
                }
            }
        }
        if(x==1){
            if(this->board[1][1] == this->board[1][2] && this->board[1][1] == this->board[1][3]){
                return true;
            }
        }
        if(x==2){
            if(y<=2 && (this->board[2][y]==this->board[2][y+1]) && (this->board[2][y+1]==this->board[2][y+2])){
                cout << this->board[2][y] << ' ' << this->board[2][y+1]<< " " << this->board[2][y+2] << "\n";
                return true;
            }
            else if(y<=3 && y>=1 && this->board[2][y]==this->board[2][y+1] && this->board[2][y+1]==this->board[2][y-1]){
                return true;
            }
            else if(y>=2 && this->board[2][y]==this->board[2][y-1]&& this->board[2][y-1] == this->board[2][y-2]){
                return true;
            }
        }
        return false;
    }

    bool is_draw(){
        if(this->n_moves==9){
            return true;
        }
        return false;
    }

    bool game_is_over(){
        if (is_draw()||is_win()){
            return true;
        }
        return false;
    }

};


template <typename T>
class Random : public RandomPlayer<T>{
public:
    Random(T symbol):RandomPlayer<T>(symbol){
        this->dimension=3;
        srand(static_cast<unsigned int>(time(0)));
    }
    void getmove(int& x, int& y){
        x = rand()%this->dimension;
        y = rand()%this->dimension;
    }

};

template <typename T>
class player : public Player<T>{
public:
    player(string N , T smp):Player<T>(N,smp){}

    void getmove(int& x , int& y){
        cout<< "Enter a Move:\n";
        cin >> x >> y;
        while(x+y==0 || x+y==1 || (x==0 && y==3) || (x==0 && y==4) || (x==1 && y==4)){
            cout << "Invalid CHOICE, PLEASE TRY AGAIN\n";
            cin >> x >> y;
        }
    }
};

void game1_main()
{
    int choice;
    Player<char> *players[2];
    string playerName1, playerName2;
    cout << "Enter Player 1 name: ";
    cin >> playerName1;
    char symbol1;
    cout << "Enter a symbol: ";
    cin >> symbol1;
    cout << "Choose Player 1 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;
    switch (choice)
    {
    case 1:
        players[0] = new player<char>(playerName2, symbol1);
        break;
    case 2:
        players[0] = new Random(symbol1);
        break;
    default:
        cout << "Invalid choice for Player 1. Exiting the game.\n";
        return;
    }

    cout << "Enter Player 2 name: ";
    cin >> playerName2;
    char symbol2;
    cout << "Enter a symbol: ";
    cin >> symbol2;
    cout << "Choose Player 2 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;

    switch (choice)
    {
    case 1:
        players[1] = new player<char>(playerName1, symbol2);
        break;
    case 2:
        players[1] = new Random(symbol2);
        break;
    default:
        cout << "Invalid choice for Player 2. Exiting the game.\n";
        return;
    }
    Game1<char> B;
    Board<char>* PtrB = &B;
    GameManager<char> round1(PtrB, players);
    round1.run();

    // Clean up
    delete PtrB;
    for (int i = 0; i < 2; ++i)
    {
        delete players[i];
    }
}

#endif //GAME1_H
