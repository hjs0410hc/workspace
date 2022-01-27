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

struct comparator{
    bool operator()(pair<int,int>& p1,pair<int,int>& p2){
        return p1.first > p2.first;
    }
};
pair<int,int> graph[1000001];

priority_queue<pair<int,int>,vector<pair<int,int>>,comparator> pq;
int v,e;
int x,y,z;
int ans = 0;
int num = 0;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> v >> e;
    for(int i=0;i<e;i++){
        cin >> x >> y>>z;
        graph[i] = {x,y};
        pq.push({z,i});
    }
    DisjointSet ds(v);
    while(num != v-2){
        pair<int,int> targetE = pq.top(); // first = 가중치 second = 해당간선의index.
        int val = targetE.first;
        int eIndex = targetE.second;
        pq.pop();
        if(ds.find(graph[eIndex].first) != ds.find(graph[eIndex].second)){
            ds.merge(graph[eIndex].first,graph[eIndex].second);
            ans += val;num++;
        }
    }
    cout << ans;
    
}