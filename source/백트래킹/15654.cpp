#include <bits/stdc++.h>
using namespace std;

int n,m,x;
vector<int> arr;
bool visited[9];
int ans[9];

void dfs(int depth){
    if(depth == m){
        for(int i=0;i<m;i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){ // 인덱스 i가 unvisited면.
            visited[i]=true;
            ans[depth] = arr[i];
            dfs(depth+1);
            visited[i]=false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    memset(visited,0,sizeof(visited));
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>x;
        arr.push_back(x);
    }
    sort(arr.begin(),arr.end());
    dfs(0);
    
}