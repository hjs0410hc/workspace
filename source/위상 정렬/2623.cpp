#include <bits/stdc++.h>
using namespace std;

int n,m,k,t;
int indegree[1001];
vector<int> graph[1001];
vector<int> rgraph[1001]; // reversed graph;
queue<int> q;
vector<int> ans;
bool visited[1001];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    memset(visited,0,sizeof(visited));
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int prev=-1;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>t;
            if(prev!=-1){
                graph[prev].push_back(t);
                rgraph[t].push_back(prev); // 1->4 이고 현재가 4고 전이 1이면 4의그래프에1을넣고4의indg를1늘린다
                indegree[t]++;
                prev=t;
            }else{
                prev=t;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        
        int target = q.front();
        if(visited[target]){cout<<0;return 0;};
        visited[target]=true;
        q.pop();
        ans.push_back(target);
        for(int i=0;i<graph[target].size();i++){
            if(--indegree[graph[target][i]]==0){
                q.push(graph[target][i]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            cout << 0;return 0;
        }
    }
    for(int i:ans){
        cout << i << "\n";
    }
}