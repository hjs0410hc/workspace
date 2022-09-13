#include <bits/stdc++.h>
using namespace std;



void solve(){
    string s;cin>>s;
    string temp = s;
    vector<pair<int,int>> v;
    bool lr = s[0] < s[s.length()-1];
    for(int i=0;i<s.length();i++){
        if(i==0 || i==s.length()-1) continue;
        if(lr && (s[i] > s[s.length()-1] || s[i] < s[0]) ){
            continue;
        }else if(!lr&& (s[i] > s[0]||s[i] < s[s.length()-1]) ){
            continue;
        }else{
            v.push_back({s[i],i});
        }
    }
    if(s[0] < s[s.size()-1]){
        sort(v.begin(),v.end());
    }else{
        sort(v.begin(),v.end(),greater<pair<int,int>>());
    }
    int cost = 0;
    if(!v.empty()){
        cost += abs(s[0] - v[0].first);
        for(int i=0;i<v.size()-1;i++){
            cost += abs(v[i].first - v[i+1].first);
        }
        cost += abs(s[s.length()-1]-v[v.size()-1].first);
    }else{
        cost = abs(s[0]-s[s.length()-1]);
    }

    int m = v.size()+2;
    cout << cost << " " << m << "\n";
    cout << 1 << " ";
    for(int i=0;i<v.size();i++){
        cout << v[i].second+1 << " ";
    }
    cout << s.size() << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;while(t--)solve();
    
    
    
    
}