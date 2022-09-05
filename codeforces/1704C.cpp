#include <bits/stdc++.h>
using namespace std;

struct iii{
    int length,x,y;
};

class ccomparator{
    public:
    bool operator()(iii& i1, iii& i2){
    return i1.length < i2.length;
}
};

bool comparator(iii& i1, iii& i2){
    return i1.length < i2.length;
}
void solve(){
    int n,m,x;cin>>n>>m; //n: 집의 개수 m:맨 처음에 감염된 집 숫자
    queue<pair<iii,int>> q;
    priority_queue<iii,vector<iii>,ccomparator> pq;
    map<int,int> status; //1 infected 2 blocked
    vector<iii> v;
    int prev = -1;
    int init = -1;
    for(int i=0;i<m;i++){
        cin>>x;
        infected[x] = true;
        if(prev != -1){
            v.push({x-prev-1,prev,x});
            prev = x;
        }else{
            prev = x;
            init = x;
        }
    }
    v.push({init-1+n-x,x,init});
    sort(v.begin(),v.end(),comparator);
    for(int i=0;i<v.size();i++){
        q.push({i,v[i]});
    }
    int index = 0;
    int ans = m;
    while(!q.empty()){
        pair<iii,int> i4 = q.front();
        iii i3 = i4.first;
        int i = i4.second; // index
        q.pop();
        int length = i3.length;
        int x = i3.x;
        int y = i3.y;
        if(i==index){
            if(status[x]==2){
                status[y]=2;
            }else{
                status[x]=2;
                status[y]=1;
                ans++;
                y=(y+1>n?1:y+1);
                q.push({{length,x,y},i});
            }
        }else{
            if(status[x] != 1){
                status[x]=1;
                ans++;
                x= x-1<1?n:x-1;
            }
            if(status[y] =1){
                status[y]=1;
                ans++;
                y=y+1<y?
            }
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