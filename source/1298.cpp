#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph(101); // 그래프
int n,m,x,y,ans{0};
bool visited[101]; // 해당 노트북이 처리되었는지? == 무조건 자리 있음.
int matched[101]; // 노트북의 주인

bool dfs(int x){
    for(int i=0;i<graph[x].size();i++){
        int dest = graph[x][i];
        if(visited[dest]){ // 해당 사람에게(i) 이미 처리된 노트북입니다 (주인의 온기가 남아있음.)
            continue;
        }else{
            visited[dest] = true;
            if(matched[dest] == 0 || dfs(matched[dest])){   // 노트북의 주인이 정해지지 않았거나(미처리) 그 주인이 다른 노트북을 가질 수 있는 경우!!!!
                matched[dest] = x; // 뺏는다;
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
    for(int i=0;i<m;i++){
        cin>>x>>y;
        graph[x].push_back(y);
    }
    for(int i=1;i<=n;i++){ // 
        memset(visited,0,sizeof(visited)); // fucking mistake
        if(dfs(i))ans++;
    }
    cout << ans;
    
}