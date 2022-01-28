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
    bool operator()(pair<double,int>& p1,pair<double,int>& p2){
        return p1.first > p2.first;
    }
};
pair<int,int> graph[100001];

priority_queue<pair<double,int>,vector<pair<double,int>>,comparator> pq;
int v,e;
double x,y;
double ans = 0L;
vector<pair<int,int>> vp; // this will be new graph...
pair<double,double> star[101];
bool visited[101];
int arr[2];
void DFS(int depth){ // this was backtracking...
    if(depth==2){
        int index = vp.size();
        vp.push_back({arr[0],arr[1]});
        double dist = sqrt(pow(star[arr[0]].first-star[arr[1]].first,2)+pow(star[arr[0]].second-star[arr[1]].second,2));
        pq.push({dist,index});
        return;
    }
    for(int i=0;i<v;i++){
        if(!visited[i]){
            visited[i]=true;
            arr[depth] = i; //0,1밖에안씀..
            DFS(depth+1);
            visited[i]=false;
        }
    }


}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    memset(visited,0,sizeof(visited));
    cin >> v;
    for(int i=0;i<v;i++){
        cin >> x >> y;
        star[i] = {x,y};
    }
    DFS(0);
    DisjointSet ds(v);
    while(!pq.empty()){
        pair<double,int> targetE = pq.top(); // first = 가중치 second = 해당간선의index.
        double val = targetE.first;
        int eIndex = targetE.second;
        pq.pop();
        if(ds.find(vp[eIndex].first) != ds.find(vp[eIndex].second)){
            ds.merge(vp[eIndex].first,vp[eIndex].second);
            ans += val;
        }
    }
    cout << ans;
    
}