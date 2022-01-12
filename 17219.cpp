#include <bits/stdc++.h>
using namespace std;

int n,m;

map<string,string> mps;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m;
    string s1,s2;
    for(int i=0;i<n;i++){
        cin >> s1 >> s2;
        mps[s1]=s2;
    }
    for(int i=0;i<m;i++){
        cin >> s1;
        cout << mps[s1] << "\n";
    }
    
    
}
