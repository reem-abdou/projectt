#ifndef GAME4_H
#define GAME4_H


#include "cmake-build-debug/BoardGame_Classes.h"
#include <string>
#include <fstream>
#include<algorithm>
using namespace std;
bool isfound (ifstream& file, const string& word){
    string tst;
    while(!file.eof()){
        tst = "";
        file.ignore(3000,word[0]);
        getline(file,tst);
        if(tst.size()==2){
            tst =  word[0] + tst;
            if(word==tst){
                return true;
            }
        }
    }
    return false;
}




template <typename T>
class Game4 : public Board<T>{
    int i,j;
    ifstream file;
public:
    Game4(): Board<T>(){
        this->rows=3;
        this->columns=3;
        this->board = new T*[3];
        this->file.open ("dic.txt");
        for (int i = 0; i < 3; ++i) {
            this->board[i] = new T[3]();
        }
    }

    ~Game4(){
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
        for(int i = 0 ; i < 3; i++){
            cout << "      ";

            for(int j = 0 ; j < 3; j++){
                if(!this->board[i][j]){
                    cout << i << "," <<j;
                }
                else{
                    cout << " " <<this->board[i][j] << " ";
                }
                cout << "   ";
            }
            cout << "\n" << "\n";
        }
    }

    bool is_win(){
        int x = this->i;
        int y = this->j;
        string word = "";
        if(x+y==2){
            if(this->board[0][2] != 0 && this->board[1][1] != 0 && this->board[2][0] != 0){
                word += this->board[0][2];
                word +=this->board[1][1];
                word += this->board[2][0];
                if(isfound(this->file,word)){
                    return true;
                }
                reverse(word.begin(),word.end());
                if(isfound(this->file,word)){
                    return true;
                }
            }
        }
        if(y==0){
            if(this->board[0][0] != 0 && this->board[1][0] != 0 && this->board[2][0] != 0){
                word+= this->board[0][0];
                word  += this->board[1][0];
                word += this->board[2][0];
                if(isfound(this->file,word)){
                    return true;
                }
                reverse(word.begin(),word.end());
                if(isfound(this->file,word)){
                    return true;
                }
            }
        }
        if(y==1){
            if(this->board[0][1] != 0 && this->board[1][1] != 0 && this->board[2][1] != 0){
                word += this->board[0][2];
                word += this->board[1][1];
                word += this->board[2][1];
                if(isfound(this->file,word)){
                    return true;
                }
                reverse(word.begin(),word.end());
                if(isfound(file,word)){
                    return true;
                }
            }
        }
        if(y==2){
            if(this->board[0][2] != 0 && this->board[1][2] != 0 && this->board[2][2] != 0){
                word  +=  this->board[0][2];
                word  += this->board[1][2];
                word  +=  this->board[2][2];
                if(isfound(this->file,word)){
                    return true;
                }
                reverse(word.begin(),word.end());
                if(isfound(this->file,word)){
                    return true;
                }
            }
        }
        if(x==1){
            if(this->board[1][0] != 0 && this->board[1][1] != 0 && this->board[1][2] != 0){
                word += this->board[1][0];
                word += this->board[1][1];
                word +=  this->board[1][2];
                if(isfound(this->file,word)){
                    return true;
                }
                reverse(word.begin(),word.end());
                if(isfound(this->file,word)){
                    return true;
                }
            }
        }
        if(x==0){
            if(this->board[0][0] != 0 && this->board[0][1] != 0 && this->board[0][2] != 0){
                word  +=  this->board[0][0];
                word  +=  this->board[0][1];
                word  +=  this->board[0][2];
                if(isfound(this->file,word)){
                    return true;
                }
                reverse(word.begin(),word.end());
                if(isfound(this->file,word)){
                    return true;
                }
            }
        }
        if(x==2){
            if(this->board[2][0] != 0 && this->board[2][1] != 0 && this->board[2][2] != 0){
                word  += this->board[2][0];
                word  += this->board[2][1];
                word  +=  this->board[2][2];
                if(isfound(this->file,word)){
                    return true;
                }
                reverse(word.begin(),word.end());
                if(isfound(this->file,word)){
                    return true;
                }
            }
        }
        if(x==y){
            if(this->board[0][0] != 0 && this->board[1][1] != 0 && this->board[2][2] != 0){
                word  +=  this->board[0][0];
                word  += this->board[1][1];
                word  += this->board[2][2];
                if(isfound(this->file,word)){
                    return true;
                }
                reverse(word.begin(),word.end());

                if(isfound(this->file,word)){
                    return true;
                }
            }
        }
        return false;
    }

    bool is_draw(){
        int x = 2;
        for(int i = 0 ; i < 3 ; i++){
            for(int j = 0 ; j < 3 ; j++){
                if(this->board[i][j]==0){
                    return false;
                }
            }
            x--;
        }
        return true;
    }

    bool game_is_over(){
        if (is_draw()||is_win()){
            return true;
        }
        return false;
    }

};

template <typename T>
class player4 : public Player<T>{
public:
    player4(string N , T smp):Player<T>(N,smp){}

    void getmove(int& x , int& y){
        cout<< "Enter a Move:\n";
        cin >> x >> y;
        while(x>3 || x<0 || y>3 || y<0){
            cout << "Invalid CHOICE, PLEASE TRY AGAIN\n";
            cin >> x >> y;
        }
        cout<< "Enter a letter:\n";
        cin >> this->symbol;
        this->symbol = toupper(this->symbol);
    }
};


template <typename T>
class Random3: public RandomPlayer<T>{
public:
    Random3(T symbol):RandomPlayer<T>(symbol){
        this->symbol = rand()%26+'A';
        this->dimension=3;
        srand(static_cast<unsigned int>(time(0)));
    }
    void getmove(int& x, int& y){
        x = rand()%this->dimension;
        y = rand()%this->dimension;
    }

};




void game4_main()
{
    int choice;
    Player<char> *players[2];
    string playerName1, playerName2;
    cout << "Enter Player 1 name: ";
    cin >> playerName1;
    cout << "Choose Player 1 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;
    switch (choice)
    {
        case 1:
            players[0] = new player4<char>(playerName2, '.');
        break;
        case 2:
            players[0] = new Random3('.');
        break;
        default:
            cout << "Invalid choice for Player 1. Exiting the game.\n";
        return;
    }

    cout << "Enter Player 2 name: ";
    cin >> playerName2;
    cout << "Choose Player 2 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;

    switch (choice)
    {
        case 1:
            players[1] = new player4<char>(playerName1, '.');
        break;
        case 2:
            players[1] = new Random3('.');
        break;
        default:
            cout << "Invalid choice for Player 2. Exiting the game.\n";
        return;
    }
    Game4<char> B;
    Board<char>* PtrB = &B;
    GameManager<char> round1(PtrB, players);
    round1.run();


    delete PtrB;
    for (int i = 0; i < 2; ++i)
    {
        delete players[i];
    }
}


#endif //GAME4_H

