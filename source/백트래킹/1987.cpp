#include <bits/stdc++.h>
using namespace std;


char mat[21][21];
bool visited[26];
int r,c;
int ans = 0;

pair<int,int> dxdy[4] = {{1,0},{-1,0},{0,1},{0,-1}};

void dfs(int x,int y,int n){
    ans = max(ans,n);
    for(int i=0;i<4;i++){
        int nx=x+dxdy[i].first;
        int ny=y+dxdy[i].second;
        if(nx >= 0 && nx < r && ny >=0 && ny < c && !visited[mat[nx][ny]-'A']){
            visited[mat[nx][ny]-'A'] = true;
            dfs(nx,ny,n+1);
            visited[mat[nx][ny]-'A'] = false;
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>r>>c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> mat[i][j];
        }
    }
    visited[mat[0][0]-'A'] = true;
    dfs(0,0,1);
    cout << ans;
}