#include <bits/stdc++.h>
using namespace std;

int m,n;
int mat[1001][1001];
//bool visited[1001][1001];
queue<pair<int,int>> q;
pair<int,int> dxdy[4] = {{1,0},{-1,0},{0,1},{0,-1}};

void BFS(){
    while(!q.empty()){
        int tr=q.front().first;
        int tc=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int ntr=tr+dxdy[i].first;
            int ntc=tc+dxdy[i].second;

            if(ntr>=0&&ntr<n&&ntc>=0&&ntc<m&&mat[ntr][ntc]==0){
                mat[ntr][ntc] = mat[tr][tc]+1; // this is important!!
                q.push({ntr,ntc});
            }
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    //memset(visited,0,sizeof(visited)); // is this unnecessary??
    cin >> m >> n;int temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> temp;mat[i][j]=temp;
            if(temp==1){
                q.push({i,j});
            }
        }
    }
    BFS();
    int maxi = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j] == 0){
                cout << -1;return 0;
            }else{
                if(mat[i][j] > maxi){
                    maxi=mat[i][j];
                }
            }
        }
    }
    cout << maxi-1;
    
}