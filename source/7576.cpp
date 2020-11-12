#include <bits/stdc++.h>
using namespace std;

int n,m;
int mapm[1001][1001];
bool visited[1001][1001];
int ans = 2e9;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
queue<pair<int,int>> q;
queue<int> nums;


void bfs(){
    int tempans = 0;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        int num = nums.front();
        nums.pop();
        tempans = max(tempans,num);
        for(int i=0;i<4;i++){
            int nx= x+dx[i];
            int ny=y+dy[i];
            if(nx >= 0 && ny >= 0 && nx < n && ny < m && mapm[nx][ny] != -1){
                if(!visited[nx][ny]){
                    mapm[nx][ny] = 1;
                    visited[nx][ny] = true;
                    q.push({nx,ny});
                    nums.push(num+1);
                }
            }
        }
    }
    ans = min(ans,tempans);
}


int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    memset(mapm,0,sizeof(mapm));
    cin>>m>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int x;cin>>x;
            mapm[i][j] = x;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mapm[i][j]==1 && !visited[i][j]){
                q.push({i,j});
                nums.push(0);
            }
        }
    }
    bfs();
    bool ac = true;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mapm[i][j] == 0){
                ac = false;
                break;
            }
        }
    }
    if(ac){
        cout << ans;
    }else{
        cout << -1;
    }
    
    
}