#include <bits/stdc++.h>
using namespace std;

int n,x,y;
int cost[501] = {0};
vector<int> graph[501];
vector<int> rgraph[501];
int indegree[501] = {0};
queue<int> q;
int maxi[501];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    memset(indegree,0,sizeof(indegree));
    memset(maxi,0,sizeof(maxi));
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x; // time cost.
        cost[i] = x;
        while(true){
            cin>>y;if(y==-1)break; // y->i이므로
            indegree[i]++;
            graph[y].push_back(i);
            rgraph[i].push_back(y);
        }
    }
    for(int i=1;i<=n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    
    while(!q.empty()){
        int target = q.front();
        q.pop();
        cost[target] += maxi[target];
        
        for(int i=0;i<graph[target].size();i++){
            maxi[graph[target][i]]= max(maxi[graph[target][i]],cost[target]);
            if(--indegree[graph[target][i]]==0){
                q.push(graph[target][i]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout << cost[i] << "\n";
    }
}