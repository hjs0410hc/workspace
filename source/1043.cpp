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
    bool inSameset(int a,int b){
        return find(a)==find(b);
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

// N: number of human M : number of parties
int n,m,truth,x,y;
vector<int> truthmen;
vector<vector<int>> parties;
int ans = 0;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m;
    DisjointSet ds(n);
    cin>>truth;
    for(int i=0;i<truth;i++){
        cin >> x;truthmen.push_back(x);
    }
    for(int i=0;i<m;i++){
        cin >>x;vector<int> p;
        for(int j=0;j<x;j++){
            cin >> y;
            p.push_back(y);
        }
        for(int j=0;j<p.size()-1;j++){
            ds.merge(p[j],p[j+1]);
        }
        parties.push_back(p);
    }
    // 진실맨과 접점이 있는 사람에겐 절대로 구라를 쳐선 안된다
    // 라는 것은 ds.find를 했을때 같은 집합에 있으면 구라ㄴ다
    for(int i=0;i<parties.size();i++){ // 파티벡터 참조중
        bool isgura = true;
        for(int j=0;j<parties[i].size();j++){ // 파티안의 사람들 참조중
            for(int q=0;q<truth;q++){ // 진실맨 참조중
                if(ds.inSameset(parties[i][j],truthmen[q])){
                    isgura = false;
                    break;
                }
            }
            if(!isgura)break;
        }
        if(isgura){
            ans++;
        }
    }
    cout << ans;

}