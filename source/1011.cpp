#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int tc;
ll x,y;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>tc;
    while(tc--){
        cin>>x>>y;
        ll dist = y-x;
        ll N = floor(sqrt(dist));
        //cout << N << "\n";
        ll ans = (2*N-1);
        ll temp = dist-N*N;
        ans += (temp%N)?temp/N+1:temp/N;
        cout << ans << "\n";
    }
    
    
}