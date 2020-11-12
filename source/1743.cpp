#include <bits/stdc++.h>
using namespace std;

int n,m,k;
int mapm[101][101];
bool visited[101][101];
int ans = 0;
int tempans = 0;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};

void bfs(int x,int y){
    visited[x][y] = true;
    tempans++;
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx <= n && ny <= m && nx > 0 && ny > 0){
            if(mapm[nx][ny] && !visited[nx][ny]){
                bfs(nx,ny);
            }
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    memset(mapm,0,sizeof(mapm));
    memset(visited,0,sizeof(visited));
    cin >> n>> m>>k;
    for(int i=0;i<k;i++){
        int x,y;cin>>x>>y;
        mapm[x][y] = 1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(mapm[i][j] && !visited[i][j]){
                bfs(i,j);
                ans = max(ans,tempans);
                tempans = 0;
            }
        }
    }
    cout << ans;
    
}