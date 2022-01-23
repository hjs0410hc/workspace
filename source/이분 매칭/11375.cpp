#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph(1001);
int n,m,x,y,ans{0};
bool visited[1001];
int matched[1001];

bool dfs(int x){
    for(int i=0;i<graph[x].size();i++){
        int dest = graph[x][i];
        if(visited[dest]){
            continue;
        }else{
            visited[dest] = true;
            if(matched[dest] == 0 || dfs(matched[dest])){
                matched[dest] = x;
                return true;
            }
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    memset(matched,0,sizeof(matched));
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>x;
        for(int j=0;j<x;j++){
            cin>>y;
            graph[i].push_back(y);
        }
    }
    for(int i=1;i<=n;i++){ // 
        memset(visited,0,sizeof(visited)); // fucking mistake
        dfs(i);
    }
    for(int i=1;i<=m;i++){
        if(matched[i] != 0)ans++;
    }
    cout << ans;
}