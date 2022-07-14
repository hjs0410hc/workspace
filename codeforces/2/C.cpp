#include <bits/stdc++.h>
using namespace std;



int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        int n,x;cin>>n; //number of wheels
        vector<int> v;
        for(int i=0;i<n;i++){
            cin>>x;
            v.push_back(x);
        }
        string s;
        for(int i=0;i<n;i++){
            cin>>x;
            cin>>s;
            for(auto c:s){
                if(c=='D'){ // i번째를 UP시키면 된다.
                    v[i] = (v[i] == 9) ? 0 : v[i]+1;
                }else{ // i번쨰를 DOWN시키면 된다.
                    v[i] = (v[i] == 0) ? 9 : v[i]-1;
                }
            }
        }
        for(auto i : v){
            cout << i << " ";
        }
        cout << "\n";
    }
    
    
    
    
}