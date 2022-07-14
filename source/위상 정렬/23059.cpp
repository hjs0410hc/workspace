#include <bits/stdc++.h>
using namespace std;

map<string,int> mp;
map<string,vector<string>> mp2;
vector<string> ans;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    string a,b;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        mp[a];
        mp[b]++;
        mp2[a].push_back(b);
    }
    priority_queue<string,vector<string>,greater<string>> pq;
    priority_queue<string,vector<string>,greater<string>> pq2;
    for(auto p : mp){
        if(p.second == 0){
            pq.push(p.first);
        }
    }
    vector<string> temp;
    while(!pq.empty()){
        string f = pq.top();
        ans.push_back(f);
        pq.pop();
        for(int i=0;i<mp2[f].size();i++){  // mp2[f] = vector, mp2[f][i] = string
            if(--mp[mp2[f][i]] == 0){
                pq2.push(mp2[f][i]);
            }
        }
        if(pq.empty()){
            while(!pq2.empty()){
                pq.push(pq2.top());
                pq2.pop();
            }
        }
    }
    if(mp.size() != ans.size()){
        cout << -1;return 0;
    }
    for(auto s:ans){
        cout << s << "\n";
    }
}