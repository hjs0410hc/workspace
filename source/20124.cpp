#include <bits/stdc++.h>
using namespace std;

bool comp(pair<string,int> &a,pair<string,int> &b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second > b.second;
}




int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    vector<pair<string,int>> v;
    for(int i=0;i<n;i++){
        string s;int c;cin>>s>>c;
        v.push_back({s,c});
    }
    sort(v.begin(),v.end(),comp);
    cout << v[0].first;
    
}