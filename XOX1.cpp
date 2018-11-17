#include <bits/stdc++.h>

using namespace std;

//X = 1
//. = 0
//O = -1
int mt[4][4];
int xwin,ywin,draw;


bool checkWin(){
    for(int i=1;i<=3;i++){
        //Yukardan asagi
        if(mt[i][1]==mt[i][2] && mt[i][2]==mt[i][3] && mt[i][1]!=0)
        {
            return true;
        }
        //Soldan saga
        if(mt[1][i]==mt[2][i] && mt[2][i]==mt[3][i] && mt[1][i]!=0)
        {
            return true;
        }
    }
    if(mt[1][1]==mt[2][2] && mt[2][2]==mt[3][3] && mt[2][2]!=0) return true;
    if(mt[3][1]==mt[2][2] &&  mt[2][2]==mt[1][3] && mt[2][2]!=0) return true;
    
    return false;
}
bool isFull(){

    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            if(mt[i][j]==0)
                return false;
        }
    }
    return true;
}
void f(int x, int y, int turn){
    mt[x][y] = turn;
    if(checkWin()){
        if(turn==-1){
            ywin++;
        }
        else{
            xwin++;
        }
        return;
        
    }
    else if(!checkWin() && isFull()){
        draw++;
        return ;
    }
    
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            if(!mt[i][j]){
                if(turn==-1)
                    f(i,j,1);
                else
                    f(i,j,-1);
                    
                mt[i][j] = 0;
            }
        }
    }
}


int main(){
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            char c;
            cin >> c;
            if(c == 'X'){
                 mt[i][j] = 1;
             }
            else if(c == 'O'){
                 mt[i][j] = -1;
            }
        }
    }
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            if(mt[i][j]==0){
                f(i,j,-1);
                mt[i][j] = 0;
            }
        }
    }
    printf("X wins: %d\n",xwin);
    printf("O wins: %d\n",ywin);
    printf("Draw: %d\n",draw);
}