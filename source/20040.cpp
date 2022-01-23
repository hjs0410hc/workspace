#include <bits/stdc++.h>
using namespace std;

// optimized Disjoint-Set implement
class DisjointSet{
    public:
    int n;
    vector<int> parent;
    vector<int> rank;
    DisjointSet(int _n) : n{_n}, parent(_n+1), rank(_n+1,0){
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }
    int find(int u){
        if(parent[u] == u){
            return u;
        }
        return parent[u] = find(parent[u]); // path compression implement
    }

    bool merge(int a,int b){
        int ap = find(a);
        int bp = find(b);
        if(ap==bp){
            return false;
        }
        // union-by-rank implement
        if(rank[ap] <= rank[bp]){ // b의 루트노드의 랭크가 a의 루트노드의 랭크보다 큼. a가 b 밑으로 가야하므로
        // ap의 parent를 bp로 설정
            parent[ap] = bp;
            rank[bp]++;
        }else{
            parent[bp] = ap;
            rank[ap]++;
        }
        return true;
    }
};

int n,m,x,y;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m;
    DisjointSet ds(n);
    int ans = 1;
    bool fail = false;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        if(ds.merge(x,y)){
            ans++;
        }else{
            fail=true;
            break;
        }
    }
    cout << ((!fail)?0:ans);
    
}