#include <bits/stdc++.h>
using namespace std;



int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        int n,m;cin >> n>>m;
        string a,b;cin>>a>>b;
        int whereisfirst =  a.find(b[0]);
        if(whereisfirst > n-m || whereisfirst == -1){
            cout << "NO\n";
            continue;
        }else{
            if(a.substr(n-m+1)==b.substr(1)){
                cout << "YES\n";
            }else{
                cout << "NO\n";
            }
        }
    }
}