#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v[101];
bool visited[101];
int ans = 0;

void bfs(int x){
    visited[x] = true;
    for(int w:v[x]){
        if(!visited[w]){
        bfs(w);
        ans++;

        }
    }
}



int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int m;cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    bfs(1);
    cout << ans;
    
}