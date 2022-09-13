#include <bits/stdc++.h>
using namespace std;

int arr[3][3];
bool visited[513];

int num = 0;

void rot_row(int row){
    for(int i=0;i<3;i++){
        arr[row][i] = !arr[row][i];
    }
}
void rot_col(int col){
    for(int i=0;i<3;i++){
        arr[i][col] = !arr[i][col];
    }
}
void rot_ort(int dir){
    if(dir==0){
        for(int i=0;i<3;i++){
            arr[i][i] = !arr[i][i];
        }
    }else if(dir==1){
        for(int i=0;i<3;i++){
            arr[2-i][i] = !arr[2-1][i];
        }
    }
}

int arrtoint(){
    int ret = 0;
    int cnt = 8;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            ret |= (arr[i][j] << cnt--);
        }
    }
    return ret;
}
int ans = 2e9;
int res = -1;
int oper[8] = {0b111000000,0b000111000,0b000000111,0b100100100,0b010010010,0b001001001,0b100010001,0b001010100};
void BFS(int x){
    queue<pair<int,int>> qpii;
    qpii.push({x,0});
    while(!qpii.empty()){
        pair<int,int> temp = qpii.front();
        if(temp.first == 0 || temp.first == 511){
            ans = min(ans,temp.second);
            break;
        }
        qpii.pop();
        for(int i=0;i<8;i++){
            int r = temp.first ^ oper[i];
            if(!visited[r])
            qpii.push({r,temp.second+1});
            visited[r]=true;
        }
    }
}

void solve(){
    ans = 2e9;
    memset(visited,0,sizeof(visited));
    char c;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin >> c;
            if(c=='H'){
                arr[i][j] = 0;
            }else{
                arr[i][j] = 1;
            }
        }
    }
    res = arrtoint();
    visited[res] = true;
    BFS(res);
    if(ans >= 2e9){
        cout << -1 << "\n";        
        return;
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc;cin>>tc;while(tc--)solve();
    
    
    
    
}