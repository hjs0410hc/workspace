#include <bits/stdc++.h>
using namespace std;

void solve(){
    string t;cin>>t;
    int n;cin>>n;
    vector<string> v;
    map<string,bool> mp;
    string x;
    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
        mp[x] = true;   
    }
    bool hascoloredchanged = false;
    int colored = 0;
    int ans = 0;
    for(int i=0;i<t.length();i++){
        for(int j=1;j<t.length()-i;j++){
            if(mp[t.substr(i,j)]==true){
                if(colored!=max(colored,i+j)){
                    hascoloredchanged=true;
                }
                colored=max(colored,i+j);
            }
        }
        if(hascoloredchanged){
            ans++;
            hascoloredchanged=false;
        }
    }
    cout << ans << "\n";
}


int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int q;cin>>q;
    while(q--)solve();   
    
    
    
    
}