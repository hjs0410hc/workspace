#include <bits/stdc++.h>
using namespace std;

int v[1001];
bool visited[1001];
int n;
int ans = 0;
void dfs(int x, int k){
    visited[x] = true;
    if(v[x] == k){
        ans++;
        return;
    }
    dfs(v[x],k);
}





int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        memset(v,0,sizeof(v));
        memset(visited,0,sizeof(visited));
        cin >> n;
        for(int i=1;i<=n;i++){
            int x;cin>>x;
            v[i] = x;
        }
        for(int i=1;i<=n;i++){
            if(!visited[i]){
                dfs(i,i);
            }
        }
        cout << ans << "\n";
        ans = 0;
    }
    
    
}