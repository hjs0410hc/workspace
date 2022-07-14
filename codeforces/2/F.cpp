#include <bits/stdc++.h>
using namespace std;



int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        int n,x;cin>>n;
        vector<pair<int,int>> v(n+1);
        long long int ans = 0;
        int num = 1;
        for(int i=1;i<=n;i++){
            cin>>x;
            v[i] = {num,x};
        }

        cout << ans << "\n";
    }
    
    
    
    
}