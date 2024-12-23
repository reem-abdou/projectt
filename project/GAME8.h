#include "cmake-build-debug/BoardGame_Classes.h"
#ifndef GAME8_H
#define GAME8_H


template <typename T>
class Game8 : public Board<T> {
    int i,j;
    int m,n;
    int count;
    T play[3][3];
public:
    Game8(): Board<T>(){
        this->rows=9;
        this->columns=9;
        this->board = new T*[9];

        for (int i = 0; i < 9; ++i) {
            this->board[i] = new T[9]();
        }
        for(int i = 0; i < 3; ++i){
            for(int j = 0; j < 3; ++j){
                play[i][j]=0;
            }
        }
    }

    ~Game8(){
        for (int i = 0; i < 9; ++i) {
            delete[] this->board[i];
        }
        delete[] this->board;

    }



    bool update_board(int x, int y, T symbol){
        if(this->board[x][y]!=0){
            cout << "This place is taken, PLEASE TRY AGAIN\n";
            return false;
        }

        if(play[x/3][y/3]!=0){
            cout << "SORRY, THIS BOARD IS CLOSED\n";
            return false;
        }
        this->board[x][y] = symbol;
        i = x;
        j = y;
        this->n_moves++;
        return true;
    }
    void display_board(){
        for(int i = 0 ; i < 9; i++){
            cout << "        ";
            for(int j = 0 ; j < 9; j++){
                if(!this->board[i][j]){
                    cout << i << "," <<j;
                }
                else{
                    cout << " " <<this->board[i][j] << " ";
                }
                if((j+1)%3==0){
                cout << "   ";
            }
                cout << "  ";

            }
            if((i+1)%3==0){
                cout << "\n" ;
            }
            cout << "\n" ;
        }
    }


    bool check(){
        int x = this->i;
        int y = this->j;
        if(x<=2 && x>=0 && y<=2 && y>=0){
            if(x+y==2){
                if(this->board[0][2] == this->board[1][1] && this->board[2][0] == this->board[1][1]){
                    play[0][0]=this->board[0][2];
                    this->m = 0;
                    this->n = 0;
                    count ++;
                    return true;
                }
            }
            if(y==0){
                if(this->board[0][0] == this->board[1][0] && this->board[2][0] == this->board[1][0]){
                    play[0][0]=this->board[0][0];
                    this->m = 0;
                    this->n = 0;
                    count ++;
                    return true;
                }
            }
            if(y==1){
                if(this->board[0][1] == this->board[1][1] &&  this->board[2][1] == this->board[1][1]){
                    play[0][0]=this->board[0][1];
                    this->m = 0;
                    this->n = 0;
                    count ++;
                    return true;
                }
            }
            if(y==2){
                if(this->board[0][2] == this->board[1][2] && this->board[2][2] == this->board[1][2]){
                    play[0][0]=this->board[0][2];
                    this->m = 0;
                    this->n = 0;
                    count ++;
                    return true;
                }
            }
            if(x==1){
                if(this->board[1][0] == this->board[1][1] && this->board[1][2] == this->board[1][1]){
                    play[0][0]=this->board[1][0];
                    this->m = 0;
                    this->n = 0;
                    count ++;
                    return true;
                }
            }
            if(x==0){
                if(this->board[0][0] == this->board[0][1] && this->board[0][2] == this->board[0][1]){
                    this->play[0][0]=this->board[0][2];
                    this->m = 0;
                    this->n = 0;
                    count ++;
                    return true;
                }
            }
            if(x==2){
                if(this->board[2][0] == this->board[2][1] && this->board[2][2] == this->board[2][1]){
                    play[0][0]=this->board[2][2];
                    this->m = 0;
                    this->n = 0;
                    count ++;
                    return true;
                }
            }
            if(x==y){
                if(this->board[0][0] == this->board[1][1] && this->board[2][2] == this->board[1][1]){
                    play[0][0]=this->board[0][0];
                    this->m = 0;
                    this->n = 0;
                    count ++;
                    return true;
                }
            }
        }


        if(x<=2 && x>=0 && y<=5 && y>=3){
            if(x+y==5){
                if(this->board[0][5] == this->board[1][4] && this->board[2][3] == this->board[1][4]){
                    this->play[0][1]=this->board[0][5];
                    this->m = 0;
                    this->n = 1;
                    count ++;
                    return true;
                }
            }
            if(y==3){
                if(this->board[0][3] == this->board[1][3] && this->board[2][3] == this->board[1][3]){
                    this->play[0][1]=this->board[0][3];
                    this->m = 0;
                    this->n = 1;
                    count ++;
                    return true;
                }
            }
            if(y==4){
                if(this->board[0][4] == this->board[1][4] &&  this->board[2][4] == this->board[1][4]){
                    this->play[0][1]=this->board[2][4];
                    this->m = 0;
                    this->n = 1;
                    count ++;
                    return true;
                }
            }
            if(y==5){
                if(this->board[0][5] == this->board[1][5] && this->board[2][5] == this->board[1][5]){
                    this->play[0][1]=this->board[0][5];
                    this->m = 0;
                    this->n = 1;
                    count ++;
                    return true;
                }
            }
            if(x==1){
                if(this->board[1][3] == this->board[1][4] && this->board[1][5] == this->board[1][4]){
                    this->play[0][1]=this->board[1][3];
                    this->m = 0;
                    this->n = 1;
                    count ++;
                    return true;
                }
            }
            if(x==0){
                if(this->board[0][3] == this->board[0][4] && this->board[0][5] == this->board[0][4]){
                   this->play[0][1]=this->board[0][3];
                    this->m = 0;
                    this->n = 1;
                    count ++;
                    return true;
                }
            }
            if(x==2){
                if(this->board[2][3] == this->board[2][4] && this->board[2][5] == this->board[2][4]){
                    this->play[0][1]=this->board[2][3];
                    this->m = 0;
                    this->n = 1;
                    count ++;
                    return true;
                }
            }
            if(x+3==y){
                if(this->board[0][3] == this->board[1][4] && this->board[2][4] == this->board[1][4]){
                    this->play[0][1]=this->board[0][3];
                    this->m = 0;
                    this->n = 1;
                    count ++;
                    return true;
                }
            }
        }


        if(x<=2 && x>=0 && y<=8 && y>=6){
            if(x+y==8){
                if(this->board[0][8] == this->board[1][7] && this->board[2][7] == this->board[1][7]){
                    this->play[0][2]=this->board[0][8];
                    this->m = 0;
                    this->n = 2;
                    count ++;
                    return true;

                }
            }
            if(y==6){
                if(this->board[0][6] == this->board[1][6] && this->board[2][6] == this->board[1][6]){
                    this->play[0][2]=this->board[0][6];
                    this->m = 0;
                    this->n = 2;
                    count ++;
                    return true;
                }
            }
            if(y==7){
                if(this->board[0][7] == this->board[1][7] &&  this->board[2][7] == this->board[1][7]){
                    this->play[0][2]=this->board[0][7];
                    this->m = 0;
                    this->n = 2;
                    count ++;
                    return true;
                }
            }
            if(y==8){
                if(this->board[0][8] == this->board[1][8] && this->board[2][8] == this->board[1][8]){
                    this->play[0][2]=this->board[0][8];
                    this->m = 0;
                    this->n = 2;
                    count ++;
                    return true;
                }
            }
            if(x==1){
                if(this->board[1][6] == this->board[1][7] && this->board[1][8] == this->board[1][7]){
                    this->play[0][2]=this->board[1][7];
                    this->m = 0;
                    this->n = 2;
                    count ++;
                    return true;
                }
            }
            if(x==0){
                if(this->board[0][6] == this->board[0][7] && this->board[0][8] == this->board[0][7]){
                    this->play[0][2]=this->board[0][7];
                    this->m = 0;
                    this->n = 2;
                    count ++;
                    return true;
                }
            }
            if(x==2){
                if(this->board[2][6] == this->board[2][7] && this->board[2][8] == this->board[2][7]){
                    this->play[0][2]=this->board[2][7];
                    this->m = 0;
                    this->n = 2;
                    count ++;
                    return true;
                }
            }
            if(x+6==y){
                if(this->board[0][6] == this->board[1][7] && this->board[2][7] == this->board[1][7]){
                    this->play[0][2]=this->board[0][6];
                    this->m = 0;
                    this->n = 2;
                    count ++;
                    return true;
                }
            }
        }


        if(x<=5 && x>=3 && y<=2 && y>=0){
            if(x+y==5){
                if(this->board[3][2] == this->board[4][1] && this->board[5][0] == this->board[4][1]){
                    this->play[1][0] = this->board[4][1];
                    this->m = 1;
                    this->n = 0;
                    count ++;
                    return true;

                }
            }
            if(y==0){
                if(this->board[3][0] == this->board[4][0] && this->board[5][0] == this->board[4][0]){
                    this->play[1][0]=this->board[4][0];
                    this->m = 1;
                    this->n = 0;
                    count++;
                    return true;
                }
            }
            if(y==1){
                if(this->board[3][1] == this->board[4][1] &&  this->board[5][1] == this->board[4][1]){
                    this->play[1][0]=this->board[3][1];
                    this->m = 1;
                    this->n = 0;
                    count++;
                    return true;
                }
            }
            if(y==2){
                if(this->board[3][2] == this->board[4][2] && this->board[5][2] == this->board[4][2]){
                    this->play[1][0]=this->board[4][2];
                    this->m = 1;
                    this->n = 0;
                    count++;
                    return true;
                }
            }
            if(x==4){
                if(this->board[4][0] == this->board[4][1] && this->board[4][2] == this->board[4][1]){
                    this->play[1][0]=this->board[4][0];
                    this->m = 1;
                    this->n = 0;
                    count ++;
                    return true;
                }
            }
            if(x==3){
                if(this->board[3][0] == this->board[3][1] && this->board[3][2] == this->board[3][1]){
                    this->play[1][0]=this->board[3][1];
                    this->m = 1;
                    this->n = 0;
                    count ++;
                    return true;
                }
            }
            if(x==5){
                if(this->board[5][0] == this->board[5][1] && this->board[5][2] == this->board[5][1]){
                    this->play[1][0]=this->board[5][0];
                    this->m = 1;
                    this->n = 0;
                    count ++;
                    return true;
                }
            }
            if(x==y+3){
                if(this->board[3][0] == this->board[4][1] && this->board[5][2] == this->board[4][1]){
                    this->play[1][0]=this->board[3][0];
                    this->m = 1;
                    this->n = 0;
                    count ++;
                    return true;
                }
            }
        }


        if(x<=8 && x>=6 && y<=2 && y>=0){
            if(x+y==8){
                if(this->board[6][2] == this->board[7][1] && this->board[8][0] == this->board[7][1]){
                    this->play[0][2]=this->board[6][2];
                    this->m = 2;
                    this->n = 0;
                    count ++;
                    return true;
                }
            }
            if(y==0){
                if(this->board[6][0] == this->board[7][0] && this->board[8][0] == this->board[7][0]){
                    this->play[2][0]=this->board[6][0];
                    this->m = 2;
                    this->n = 0;
                    count ++;
                    return true;
                }
            }
            if(y==1){
                if(this->board[6][1] == this->board[7][1] &&  this->board[8][1] == this->board[7][1]){
                    this->play[2][0]=this->board[6][1];
                    this->m = 2;
                    this->n = 0;
                    count ++;
                    return true;
                }
            }
            if(y==2){
                if(this->board[6][2] == this->board[7][2] && this->board[8][2] == this->board[7][2]){
                    this->play[2][0]=this->board[6][2];
                    this->m = 2;
                    this->n = 0;
                    count ++;
                    return true;
                }
            }
            if(x==7){
                if(this->board[7][0] == this->board[7][1] && this->board[7][2] == this->board[7][1]){
                    this->play[2][0]=this->board[7][2];
                    this->m = 2;
                    this->n = 0;
                    count ++;
                    return true;
                }
            }
            if(x==6){
                if(this->board[6][0] == this->board[6][1] && this->board[6][2] == this->board[6][1]){
                    this->play[2][0]=this->board[6][2];
                    this->m = 2;
                    this->n = 0;
                    count ++;
                    return true;
                }
            }
            if(x==8){
                if(this->board[8][0] == this->board[8][1] && this->board[8][2] == this->board[8][1]){
                    this->play[2][0]=this->board[8][2];
                    this->m = 2;
                    this->n = 0;
                    count ++;
                    return true;
                }
            }
            if(x==y+6){
                if(this->board[6][0] == this->board[7][1] && this->board[8][2] == this->board[7][1]){
                    this->play[2][0]=this->board[8][2];
                    this->m = 2;
                    this->n = 0;
                    count ++;
                    return true;
                }
            }
        }


        if(x<=5 && x>=3 && y<=5 && y>=3){
            if(x+y==8){
                if(this->board[3][5] == this->board[4][4] && this->board[5][3] == this->board[4][4]){
                    this->play[1][1]=this->board[3][5];
                    this->m = 1;
                    this->n = 1;
                    count ++;
                    return true;
                }
            }
            if(y==3){
                if(this->board[3][3] == this->board[4][3] && this->board[5][3] == this->board[4][3]){
                    this->play[1][1]=this->board[3][3];
                    this->m = 1;
                    this->n = 1;
                    count ++;
                    return true;
                }
            }
            if(y==4){
                if(this->board[3][4] == this->board[4][4] &&  this->board[5][4] == this->board[4][4]){
                    this->play[1][1]=this->board[3][4];
                    this->m = 1;
                    this->n = 1;
                    count ++;
                    return true;
                }
            }
            if(y==5){
                if(this->board[3][5] == this->board[4][5] && this->board[5][5] == this->board[4][5]){
                    this->play[1][1]=this->board[3][5];
                    this->m = 1;
                    this->n = 1;
                    count ++;
                    return true;
                }
            }
            if(x==4){
                if(this->board[4][3] == this->board[4][4] && this->board[4][5] == this->board[4][4]){
                    this->play[1][1]=this->board[4][3];
                    this->m = 1;
                    this->n = 1;
                    count ++;
                    return true;
                }
            }
            if(x==3){
                if(this->board[3][0] == this->board[3][1] && this->board[3][2] == this->board[3][1]){
                    this->play[1][1]=this->board[3][0];
                    this->m = 1;
                    this->n = 1;
                    count ++;
                    return true;
                }
            }
            if(x==5){
                if(this->board[5][3] == this->board[5][4] && this->board[5][5] == this->board[5][4]){
                   this->play[1][1]=this->board[5][3];
                    this->m = 1;
                    this->n = 1;
                    count ++;
                    return true;
                }
            }
            if(x==y){
                if(this->board[3][3] == this->board[4][4] && this->board[5][5] == this->board[4][4]){
                    this->play[1][1]=this->board[3][3];
                    this->m = 1;
                    this->n = 1;
                    count ++;
                    return true;
                }
            }
        }

        if(x<=5 && x>=3 && y<=8 && y>=6){
            if(x+y==11){
                if(this->board[3][8] == this->board[4][7] && this->board[5][6] == this->board[4][7]){
                    this->play[1][2]=this->board[3][8];
                    this->m = 1;
                    this->n = 2;
                    count ++;
                    return true;
                }
            }
            if(y==6){
                if(this->board[3][6] == this->board[4][6] && this->board[5][6] == this->board[4][6]){
                    this->play[1][2]=this->board[3][6];
                    this->m = 1;
                    this->n = 2;
                    count ++;
                    return true;
                }
            }
            if(y==7){
                if(this->board[3][7] == this->board[4][7] &&  this->board[5][7] == this->board[4][7]){
                    this->play[1][2]=this->board[3][7];
                    this->m = 1;
                    this->n = 2;
                    count ++;
                    return true;
                }
            }
            if(y==8){
                if(this->board[3][8] == this->board[4][8] && this->board[5][8] == this->board[4][8]){
                    this->play[1][2]=this->board[3][8];
                    this->m = 1;
                    this->n = 2;
                    count ++;
                    return true;
                }
            }
            if(x==4){
                if(this->board[4][6] == this->board[4][7] && this->board[4][8] == this->board[4][7]){
                    this->play[1][2]=this->board[4][8];
                    this->m = 1;
                    this->n = 2;
                    count ++;
                    return true;
                }
            }
            if(x==3){
                if(this->board[3][6] == this->board[3][7] && this->board[3][8] == this->board[3][7]){
                    this->play[1][2]=this->board[3][8];
                    this->m = 1;
                    this->n = 2;
                    count ++;
                    return true;
                }
            }
            if(x==5){
                if(this->board[5][6] == this->board[5][7] && this->board[5][8] == this->board[5][7]){
                   this->play[1][2]=this->board[5][8];
                    this->m = 1;
                    this->n = 2;
                    count ++;
                    return true;
                }
            }
            if(x+3==y){
                if(this->board[3][6] == this->board[4][7] && this->board[5][8] == this->board[4][7]){
                    this->play[1][2]=this->board[3][6];
                    this->m = 1;
                    this->n = 2;
                    count ++;
                    return true;
                }
            }
        }

        if(x<=8 && x>=6 && y<=8 && y>=6){
            if(x+y==14){
                if(this->board[6][8] == this->board[7][7] && this->board[8][6] == this->board[7][7]){
                    this->play[2][2]=this->board[6][8];
                    this->m = 2;
                    this->n = 2;
                    count ++;
                    return true;
                }
            }
            if(y==6){
                if(this->board[6][6] == this->board[7][6] && this->board[8][6] == this->board[7][6]){
                    this->play[2][2]=this->board[6][6];
                    this->m = 2;
                    this->n = 2;
                    count ++;
                    return true;
                }
            }
            if(y==7){
                if(this->board[6][7] == this->board[7][7] &&  this->board[8][7] == this->board[7][7]){
                    this->play[2][2]=this->board[6][7];
                    this->m = 2;
                    this->n = 2;
                    count ++;
                    return true;
                }
            }
            if(y==8){
                if(this->board[6][8] == this->board[7][8] && this->board[8][8] == this->board[7][8]){
                    this->play[2][2]=this->board[6][8];
                    this->m = 2;
                    this->n = 2;
                    count ++;
                    return true;
                }
            }
            if(x==7){
                if(this->board[7][6] == this->board[7][7] && this->board[7][8] == this->board[7][7]){
                    this->play[2][2]=this->board[7][8];
                    this->m = 2;
                    this->n = 2;
                    count ++;
                    return true;
                }
            }
            if(x==6){
                if(this->board[6][6] == this->board[6][7] && this->board[6][8] == this->board[6][7]){
                    this->play[2][2]=this->board[6][8];
                    this->m = 2;
                    this->n = 2;
                    count ++;
                    return true;
                }
            }
            if(x==8){
                if(this->board[8][6] == this->board[8][7] && this->board[8][8] == this->board[8][7]){
                    this->play[2][2]=this->board[8][8];
                    this->m = 2;
                    this->n = 2;
                    count ++;
                    return true;
                }
            }
            if(x==y){
                if(this->board[6][6] == this->board[7][7] && this->board[8][8] == this->board[7][7]){
                    this->play[2][2]=this->board[8][8];
                    this->m = 2;
                    this->n = 2;
                    count ++;
                    return true;
                }
            }
        }

        if(x<=8 && x>=6 && y<=3 && y>=8){
            if(x+y==11){
                if(this->board[6][5] == this->board[7][4] && this->board[8][3] == this->board[7][4]){
                    this->play[2][1]=this->board[6][5];
                    this->m = 2;
                    this->n = 1;
                    count ++;
                    return true;

                }
            }
            if(y==3){
                if(this->board[6][3] == this->board[7][3] && this->board[8][3] == this->board[7][3]){
                    this->play[2][1]=this->board[6][3];
                    this->m = 2;
                    this->n = 1;
                    count ++;
                    return true;
                }
            }
            if(y==4){
                if(this->board[6][4] == this->board[7][4] &&  this->board[8][4] == this->board[7][4]){
                    this->play[2][1]=this->board[6][4];
                    this->m = 2;
                    this->n = 1;
                    count ++;
                    return true;
                }
            }
            if(y==5){
                if(this->board[6][5] == this->board[7][5] && this->board[8][5] == this->board[7][5]){
                    this->play[2][1]=this->board[6][5];
                    this->m = 2;
                    this->n = 1;
                    count ++;
                    return true;
                }
            }
            if(x==7){
                if(this->board[7][3] == this->board[7][4] && this->board[7][5] == this->board[7][4]){
                    this->play[2][1]=this->board[7][4];
                    this->m = 2;
                    this->n = 1;
                    count ++;
                    return true;
                }
            }
            if(x==6){
                if(this->board[6][3] == this->board[6][4] && this->board[6][5] == this->board[6][4]){
                    this->play[2][1]=this->board[6][3];
                    this->m = 2;
                    this->n = 1;
                    count ++;
                    return true;
                }
            }
            if(x==8){
                if(this->board[8][3] == this->board[8][4] && this->board[8][5] == this->board[8][4]){
                    this->play[2][1]=this->board[8][5];
                    this->m = 2;
                    this->n = 1;
                    count ++;
                    return true;
                }
            }
            if(x==y+3){
                if(this->board[6][3] == this->board[7][4] && this->board[8][5] == this->board[7][4]){
                    this->play[2][1]=this->board[6][3];
                    this->m = 2;
                    this->n = 1;
                    count ++;
                    return true;
                }
            }
        }
        return false;

    }



    bool is_win(){
        this->check();
        if(play[m][n]==0 || m>3 || n>3){
            return false;
        }
        if(m+n==2){
            if(this->play[0][2] == this->play[1][1] && this->play[2][0] == this->play[1][1]){
               return true;
            }
        }
        if(n==0){
            if(this->play[0][0] == this->play[1][0] && this->play[2][0] == this->play[1][0]){
                return true;
            }
        }
        if(n==1){
            if(this->play[0][1] == this->play[1][1]  && this->play[2][1] == this->play[1][1]){
                return true;
            }
        }
        if(n==2){
            if(this->play[0][2] == this->play[1][2] && this->play[2][2] == this->play[1][2]){
                return true;

            }
        }
        if(m==1){
            if(this->play[1][0] == this->play[1][1]  && this->play[1][2] == this->play[1][1]){
                return true;
            }
        }
        if(m==0){
            if(this->play[0][0] == this->play[0][1]  && this->play[0][2] == this->play[0][1]){
                return true;
            }
        }
        if(m==2){
            if(this->play[2][0] == this->play[2][1]  && this->play[2][2] == this->play[2][1]){
               return true;
        }
        }
        if(m==n){
            if(this->play[0][0] == this->play[1][1]  && this->play[2][2] == this->play[1][1]){
                return true;;
            }
        }
        return false;
    }
    bool is_draw(){
        if(this->n_moves==81 || count==9){
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
class playerG8 : public Player<T>{
public:
    playerG8(string N , T smp):Player<T>(N,smp){}

    void getmove(int& x , int& y){
        cout<< "Enter a Move:\n";
        cin >> x >> y;
        while(x>8 || x<0 || y>8 || y<0){
            cout << "Invalid CHOICE, PLEASE TRY AGAIN\n";
            cin >> x >> y;
        }
    }
};


template <typename T>
class Random2:public RandomPlayer<T>{
public:
    Random2(T symbol):RandomPlayer<T>(symbol){
        this->dimension=9;
        srand(static_cast<unsigned int>(time(0)));
    }
    void getmove(int& x, int& y){
      x = rand()%this->dimension;
      y = rand()%this->dimension;
    }

};

void game8_main()
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
            players[0] = new playerG8<char>(playerName1, symbol1);
        break;
        case 2:
            players[0] = new Random2(symbol1);
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
            players[1] = new playerG8<char>(playerName2, symbol2);
        break;
        case 2:
            players[1] = new Random2(symbol2);
        break;
        default:
            cout << "Invalid choice for Player 2. Exiting the game.\n";
        return;
    }
    Game8<char> B;
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

#endif //_BOARDGAME_CLASSES_H
