#include <bits/stdc++.h>
using namespace std;

int n,m,a,b;
int indegree[32001];
vector<int> graph[32001];
queue<int> q;


int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin >> a>>b; // a->b
        indegree[b]++;
        graph[a].push_back(b);
    }
    for(int i=1;i<=n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int t = q.front();
        q.pop();
        cout << t << " ";
        for(int j=0;j<graph[t].size();j++){
            if(--indegree[graph[t][j]]==0){
                q.push(graph[t][j]);
            }
        }
    }
    
}