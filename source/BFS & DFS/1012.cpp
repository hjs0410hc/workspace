#include <bits/stdc++.h>
using namespace std;

const int N=51;
bool mapm[N][N];
bool visited[N][N];
int ans = 0;
int t,n,m,k;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};

void dfs(int x, int y){
    visited[x][y] = true;
    for(int i=0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx >= 0 && ny >= 0 && nx < n && ny < m){
            if(mapm[nx][ny] && !visited[nx][ny]){
                dfs(nx,ny);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--){
        memset(visited,0,sizeof(visited));
        memset(mapm,0,sizeof(mapm));
        ans=0;
        cin>>n>>m>>k;
        for(int i=0;i<k;i++){
            int x,y;cin>>x>>y;
            mapm[x][y] = true;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && mapm[i][j]){
                    dfs(i,j);
                    ans++;
                }
            }
        }
        cout << ans << "\n";
    }
}