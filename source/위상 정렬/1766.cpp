#include <bits/stdc++.h>
using namespace std;

int n,m,x,y;
int indegree[32001];
vector<int> graph[32001];
vector<int> ans;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin >> x >> y;
        indegree[y]++;
        graph[x].push_back(y);
    }
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=1;i<=n;i++){
        if(indegree[i] == 0){
            pq.push(i);
        }
    }
    while(!pq.empty()){
        int t = pq.top();
        pq.pop();
        for(int i=0;i<graph[t].size();i++){
            if((--indegree[graph[t][i]]) == 0){
                pq.push(graph[t][i]);
            }
        }
        ans.push_back(t);
    }
    for(int i : ans){
        cout << i << " ";
    }
}