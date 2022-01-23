#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int>v[10001];
int tempans = -1;
bool visited[10001];


void dfs(int x){
    visited[x] = true;
    tempans++;
    for(int w : v[x]){
        if(!visited[w]){
            dfs(w);
        }
    }
}

bool comp(pair<int,int>& a,pair<int,int>& b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second > b.second;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        v[y].push_back(x);
    }
    vector<pair<int,int>> ansv;
    for(int i=1;i<=n;i++){
        tempans = -1;
        memset(visited,0,sizeof(visited));
        dfs(i);
        ansv.push_back({i,tempans});
    }
    sort(ansv.begin(),ansv.end(),comp);
    int max = ansv[0].second;
    if(max == 0)return 0;
    for(int i=0;i<ansv.size();i++){
        if(ansv[i].second != max){
            break;
        }
        cout << ansv[i].first << " ";
    }

}