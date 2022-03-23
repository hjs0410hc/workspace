#include <bits/stdc++.h>
using namespace std;

int n,m,x,y,k,a,b;
int mat[21][21];
pair<int,int> dxdy[5] = {{0,0},{0,1},{0,-1},{-1,0},{1,0}};
// 동 서 북 남 1 2 3 4
int dice[6];
int dice0{0},dice1{1},dice2{2},dice3{3},dice4{4},dice5{5};
// dice0을 주사위의 윗면으로 간주. 각각의 변수의 값은 dice 배열의 index값임.


//   1
// 3 0 2
//   4
//   5

// x가 row y가 col이었다.



void diceMove(int dir){
    int temp = dice5;
    switch(dir){
        case 1: //동
            dice5=dice2; dice2=dice0; dice0=dice3; dice3=temp;
            break;
        case 2: //서
            dice5=dice3; dice3=dice0; dice0=dice2; dice2=temp;
            break;
        case 3: // 북
            dice5=dice1; dice1=dice0; dice0=dice4; dice4=temp;
            break;
        case 4: //남
            dice5=dice4; dice4=dice0; dice0=dice1; dice1=temp;
            break;
    }
}



int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    memset(dice,0,sizeof(dice));
    cin>>n>>m>>x>>y>>k;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    // 동 서 북 남 1 2 3 4
    for(int i=0;i<k;i++){
        cin >> a;
        int nx,ny;
        nx = x+dxdy[a].first;ny=y+dxdy[a].second;
        if(nx>=0&&ny>=0&&nx<n&&ny<m){
            if(mat[x][y] == 0){
                mat[x][y] = dice[dice5];
            }else{
                dice[dice5]= mat[x][y];
                mat[x][y] = 0;
            }
            x=nx;y=ny;
            diceMove(a);
            cout << dice[dice0] << "\n";
        }
    }
    
}