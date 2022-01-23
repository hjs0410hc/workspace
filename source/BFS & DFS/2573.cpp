// 7 tries. 문제를 제대로 안 읽고 풀었음 adhd가 의심됨

#include <bits/stdc++.h>
using namespace std;

int n,m;
int mapm[301][301];
int decmap[301][301];
bool visited[301][301]; // DFS 처음 시작할때 무조건 초기화하기

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

void dfs(int x,int y){
    visited[x][y] = true;
    for(int i=0;i<4;i++){
        int nx= x+dx[i];
        int ny= y+dy[i];
        if(nx >= 0 && ny >= 0 && nx < n && ny < m){
            if(mapm[nx][ny] != 0 && !visited[nx][ny]){
                dfs(nx,ny);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);std::cout.tie(0);
    cin >> n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mapm[i][j];
        }
    }
    bool onlyoneisland = true;
    int ans = 0;
    int k=0;        

    int temp = 0;
    memset(visited,0,sizeof(visited));          // 맨처음부터 섬이 0개거나 2개 이상일 경우를 찾음
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j] && mapm[i][j] != 0){
                dfs(i,j);
                temp++;
            }
        }
    }
    if(temp != 1){
        onlyoneisland = false;
    }
    while(onlyoneisland){
        for(int i=0;i<n;i++){ // 1 줄이기
            for(int j=0;j<m;j++){
                if(mapm[i][j] != 0){
                    int dec = 0;
                    for(int p=0;p<4;p++){
                        int nx = i+dx[p];
                        int ny = j+dy[p];
                        if(mapm[nx][ny]==0){
                            dec++;
                        }
                    }
                    decmap[i][j] = dec;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mapm[i][j] -= decmap[i][j];
                if(mapm[i][j] < 0){
                    mapm[i][j] = 0;
                }
            }
        }
        k++;
        int temp = 0;
        memset(visited,0,sizeof(visited));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && mapm[i][j] != 0){
                    dfs(i,j);
                    temp++;
                }
            }
        }
        if(temp == 0){
            ans = 0;
            onlyoneisland = false;
        }else if(temp != 1){
            onlyoneisland = false;
            ans = k;
        }
    }
    std::cout << ans;
}