#include <bits/stdc++.h>
using namespace std;



int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        string s;cin>>s;
        map<char,bool> visited;
        int ans = 0;
        for(auto c:s){
            if(visited[c]==true){
                ans+=1;
            }else{
                visited[c]=true;
                ans+=2;
            }
        }
        cout << ans << "\n";
    }
    
    
    
    
}