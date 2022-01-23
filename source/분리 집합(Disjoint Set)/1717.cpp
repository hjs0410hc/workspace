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
    void merge(int a,int b){
        int ap = find(a);
        int bp = find(b);
        if(ap==bp) return;
        // union-by-rank implement
        if(rank[ap] <= rank[bp]){ // b의 루트노드의 랭크가 a의 루트노드의 랭크보다 큼. a가 b 밑으로 가야하므로
        // ap의 parent를 bp로 설정
            parent[ap] = bp;
            rank[bp]++;
        }else{
            parent[bp] = ap;
            rank[ap]++;
        }
    }
};

int n,m;
int x,y,z;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n>>m;
    DisjointSet ds(n);
    for(int i=0;i<m;i++){
        cin >> x;
        // 0 : union 1 : find.
        if(x==0){
            cin>>y>>z;
            ds.merge(y,z);
        }else{
            cin>>y>>z;
            cout << ((ds.find(y) == ds.find(z))?"YES":"NO") << "\n";
        }
    }
    
    
}