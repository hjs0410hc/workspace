#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,x;cin>>n>>x;
    int piles[n+1];
    for(int i=1;i<=n;i++){
        cin>>piles[i];
    }
    int s=piles[1]-x;
    int e=piles[1]+x;
    int count = 0;
    for(int i=2;i<=n;i++){
        int ns = piles[i]-x;
        int ne = piles[i]+x;
        if(e < ns || s > ne){ // 겹칠 수 없음
            count++;
            s = ns;
            e = ne;
        }else{
            if(ns > s){
                s = ns;
            }
            if(ne < e){
                e = ne;
            }
        }
    }
    cout << count << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
    
    
    
    
}