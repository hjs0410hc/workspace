#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<string> v;
        map<string,bool> mp;
        string x;
        for(int i=0;i<n;i++){
            cin>>x;
            v.push_back(x);
            mp[x]=true;
        }
        for(int i=0;i<n;i++){
            bool success = false;
            for(int j=1;j<v[i].length();j++){
                string prefix = v[i].substr(0,j);
                string suffix = v[i].substr(j,v[i].length()-j);
                if(mp[prefix] && mp[suffix]){
                    success=true;
                    break;
                }
            }
            if(success){
                cout << 1;
            }else{
                cout << 0;
            }
        }
        cout << "\n";
    }
    
    
    
    
}