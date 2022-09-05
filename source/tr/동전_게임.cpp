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
void BF(){
    if(res == 0 || res == 511){
        ans = min(ans,num);
        return;
    }
    res ^= 0b111000000;
    if(!visited[res]){
        num++;
        visited[res] = true;
        BF();
        num--;
        res ^= 0b111000000;
    }
    res ^= 0b000111000;
    if(!visited[res]){
        num++;
        BF();
        num--;
        res ^= 0b000111000;
    }
    res ^= 0b000000111;
    if(!visited[res]){
        num++;
        BF();
        num--;
        res ^= 0b000000111;
    }
    res ^= 0b100100100;
    if(!visited[res]){
        num++;
        BF();
        num--;
        res ^= 0b100100100;
    }
    res ^= 0b010010010;
    if(!visited[res]){
        num++;
        BF();
        num--;
        res ^= 0b010010010;
    }
    res ^= 0b001001001;
    if(!visited[res]){
        num++;
        BF();
        num--;
        res ^= 0b001001001;
    }
    res ^= 0b100010001;
    if(!visited[res]){
        num++;
        BF();
        num--;
        res ^= 0b100010001;
    }
    res ^= 0b001010100;
    if(!visited[res]){
        num++;
        BF();
        num--;
        res ^= 0b001010100;
    }
}

void solve(){
    ans = 0;
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
    BF();
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc;cin>>tc;while(tc--)solve();
    
    
    
    
}