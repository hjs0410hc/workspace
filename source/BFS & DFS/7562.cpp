#include <bits/stdc++.h>
using namespace std;

int dx[8] ={2,1,-1,-2,-2,-1,1,2};
int dy[8] ={1,2,2,1,-1,-2,-2,-1};

int l;
int cx{0},cy{0};
int tx{0},ty{0};
int ans;
bool visited[301][301];

void bfs(int x,int y){
    visited[x][y] = true;
    queue<pair<int,int>> xy;
    queue<int> nums;
    xy.push({x,y});
    nums.push(0);
    while(!xy.empty()){
        int x=xy.front().first;
        int y=xy.front().second;
        int num = nums.front();
        xy.pop();
        nums.pop();
        if(x == tx && y == ty){
            ans = min(ans,num);
        }
        for(int i=0;i<8;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx >= 0 && ny >= 0 && nx < l && ny < l){
                if(!visited[nx][ny]){
                    visited[nx][ny] = true;
                    xy.push({nx,ny});
                    nums.push(num+1);
                }
            }
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        cin>>l;
        cin >> cx>>cy;
        cin >> tx>>ty;
        ans = 2e9;
        memset(visited,0,sizeof(visited));
        bfs(cx,cy);
        cout << ans << endl;
    }
}