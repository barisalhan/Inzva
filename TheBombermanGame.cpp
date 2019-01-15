
#include <bits/stdc++.h>

using namespace std;
char ar[300][300];
int r,c,n;
void change(){
    queue<pair<int,int>> temp;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            if(ar[i][j]=='O'){
                temp.push({i,j});
                if(i-1>0) temp.push({i-1,j});
                if(j-1>0) temp.push({i,j-1});
                if(i+1<=r) temp.push({i+1,j});
                if(j+1<=c) temp.push({i,j+1});
            }
        }
    }
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            ar[i][j] ='O';
        }
    }
    while(!temp.empty())
    {
        pair<int,int> a = temp.front();
        temp.pop();
        ar[a.first][a.second] = '.';
    }

}
void display(bool flag = false){
    if(flag){
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                cout<<'O';
            }
            cout<< endl;
        }
    }
    else{
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                cout<< ar[i][j];
            }
            cout << endl;
        }
    }

}
int main(){
    scanf("%d %d %d",&r,&c,&n);
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin >> ar[i][j];
        }
    }
    if(n==1) display();

    else if((n&1) == 0){
        display(true);
    }

    else if((n+1)%4==0){
        change();
        display();
    }
    else{
        change();
        change();
        display();
    }


}
