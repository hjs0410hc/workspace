#include <bits/stdc++.h>
using namespace std;

int w,h;
int mapm[51][51];
int visited[51][51];
int ans = 0;

int dx[8] ={1,1,0,-1,0,-1,-1,1};
int dy[8] ={1,0,1,-1,-1,0,1,-1};

void dfs(int x,int y){
    visited[x][y]=true;
    for(int i=0;i<8;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx >= 0 && ny >= 0 && nx < h && ny < w){
            if(mapm[nx][ny] && !visited[nx][ny]){
                dfs(nx,ny);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    while(true){
        memset(mapm,0,sizeof(mapm));
        memset(visited,0,sizeof(visited));
        ans = 0;
        cin>>w>>h;
        if(w==0 && h==0){break;}
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                int x;cin>>x;
                mapm[i][j] = x;
            }
        } // 입력완료

        // DFS OK
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(mapm[i][j] && !visited[i][j]){
                    dfs(i,j);
                    ans++;
                }
            }
        }
        cout << ans << "\n";
    }
    
    
}