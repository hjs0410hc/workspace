#include <bits/stdc++.h>
using namespace std;

int n;
int a,b;
int par[101];
bool visited[101];
vector<int> v[101];

void bfs(int x, int y){
    queue<int> q;
    queue<int> nums;
    visited[x]=true;
    q.push(x);
    nums.push(0);
    int tempans = 0;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        int num = nums.front();
        nums.pop();
        if(x==y){
            tempans=num;
            break;
        }
        if(par[x] != 0 && !visited[par[x]]){
            visited[par[x]] = true;
            q.push(par[x]);
            nums.push(num+1);
        }
        for(int w:v[x]){
            if(!visited[w]){
                visited[w]= true;
                q.push(w);
                nums.push(num+1);
            }
        }
    }
    if(tempans == 0){
        cout << -1;
    }else{
        cout << tempans;
    }
}


int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    memset(par,0,sizeof(par));
    cin>>n>>a>>b;
    int m;cin>>m;
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        v[x].push_back(y);
        par[y] = x;
    }
    bfs(a,b);
}