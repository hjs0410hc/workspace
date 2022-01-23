#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph(201); // 그래프
int n,m,x,y,ans{0};
bool visited[201]; // 해당 축사가 처리되었는지?
int matched[201]; // 노트북의 주인

bool dfs(int x){
    for(int i=0;i<graph[x].size();i++){
        int dest = graph[x][i];
        if(visited[dest]){ // 해당 소에게(i) 이미 처리된 축사입니다
            continue;
        }else{
            visited[dest] = true;
            if(matched[dest] == 0 || dfs(matched[dest])){   // 축사의 주인이 정해지지 않았거나(미처리) 그 소가 다른 축사를 가질 수 있는 경우!!!!
                matched[dest] = x; // 자리뺏는다;
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
        if(dfs(i))ans++;
    }
    cout << ans;
    
}