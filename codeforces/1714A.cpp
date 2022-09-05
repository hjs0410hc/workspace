#include <bits/stdc++.h>
using namespace std;

void timecalc(int h1,int m1,int h2,int m2){ // 1이 2보다 큼을 가정함
    int hc = h1-h2;
    int mc = m1-m2;
    if(mc<0){
        hc--;
        mc+=60;
    }
    if(hc<0){
        hc+=24;
    }
    cout << hc<<" "<<mc<<"\n";
}

void solve(){
    int n,h,m;cin>>n>>h>>m;
    int x,y;
    vector<pair<int,int>> v;
    v.push_back({h,m});
    bool thereisthesame = false;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        v.push_back({x,y});
        if(x==h && y==m){
            thereisthesame=true;
        }
    }
    if(thereisthesame){
        cout << "0 0\n";
        return;
    }
    sort(v.begin(),v.end());
    pair<int,int> latest = *(--v.end());
    bool success = false;
    for(int i=0;i<=n;){
        if(v[i].first == h && v[i].second == m){
            success=true;
        }else if(success){
            timecalc(v[i].first,v[i].second,h,m);
            return;
        }
        if(i+1>n){
            i=0;
        }else{
            i++;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
    
    
    
    
}