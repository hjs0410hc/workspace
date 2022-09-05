#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll s,b;
ll v[11];
vector<pair<ll,ll>> vpll;
bool visited[11];
ll ans = INT64_MAX;
int num = 0;
ll ss = 1;
ll bb = 0;



void solve(){
    if(num == n){
        return;
    }else{
        for(int i=0;i<n;i++){
            if(visited[i]){
                continue;
            }
            ss *= vpll[i].first;
            bb += vpll[i].second;
            visited[i] = true;
            num++;
            solve();
            ans = min(ans,abs(ss-bb));
            num--;
            visited[i]=false;
            ss /= vpll[i].first;
            bb -= vpll[i].second;
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> s >> b;
        vpll.push_back({s,b});
    }
    solve();
    cout << ans;
}