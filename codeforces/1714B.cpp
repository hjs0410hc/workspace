#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n,x; cin >> n;
    bool visited[n+1];
    memset(visited,0,sizeof(visited));
    vector<int> v;
    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }
    int ans = 0;
    for(int i=v.size()-1;i>=0;i--){
        if(!visited[v[i]]){
            visited[v[i]]=true;
        }else{
            ans = i+1;
            break;
        }
    }
    cout << ans << "\n";
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}