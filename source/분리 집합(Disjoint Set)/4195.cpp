#include <bits/stdc++.h>
using namespace std;

// optimized Disjoint-Set implement
class DisjointSet{
    public:
    int n;
    vector<int> parent;
    vector<int> rank;
    DisjointSet(int _n) : n{_n}, parent(_n+1), rank(_n+1,1){
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
        if(ap==bp){
            cout << rank[ap] << "\n";
            return;
        };
        // union-by-rank implement
        if(rank[ap] <= rank[bp]){ // b의 루트노드의 랭크가 a의 루트노드의 랭크보다 큼. a가 b 밑으로 가야하므로
        // ap의 parent를 bp로 설정
            parent[ap] = bp;
            rank[bp] += rank[ap];
            cout << rank[bp] << "\n";
        }else{
            parent[bp] = ap;
            rank[ap] += rank[bp];
            cout << rank[ap] << "\n";
        }
    }
};


int tc,f;
string s1,s2;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>tc;
    while(tc--){
        cin >> f;
        map<int,string> mp;
        map<string,int> mp2;
        int human = 0;
        DisjointSet ds(200001);
        for(int i=0;i<f;i++){
            cin >> s1 >> s2;
            if(mp2[s1] == 0){
                human++;
                mp[human] = s1;
                mp2[s1] = human;
            }
            if(mp2[s2] == 0){
                human++;
                mp[human] = s2;
                mp2[s2] = human;
            }
            ds.merge(mp2[s1],mp2[s2]);
        }
    }
    
    
}