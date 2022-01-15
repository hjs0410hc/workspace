#include <bits/stdc++.h>
using namespace std;

int m,n,h;
int mat[101][101][101]; // height , row, col
//bool visited[1001][1001];
queue<tuple<int,int,int>> q;
tuple<int,int,int> dxdy[6] = {{0,1,0},{0,-1,0},{0,0,1},{0,0,-1},{1,0,0},{-1,0,0}};

void BFS(){
    while(!q.empty()){
        int th=get<0>(q.front());
        int tr=get<1>(q.front());
        int tc=get<2>(q.front());
        q.pop();
        for(int i=0;i<6;i++){
            int nth=th+get<0>(dxdy[i]);
            int ntr=tr+get<1>(dxdy[i]);
            int ntc=tc+get<2>(dxdy[i]);

            if(nth>=0&&nth<h&&ntr>=0&&ntr<n&&ntc>=0&&ntc<m&&mat[nth][ntr][ntc]==0){
                mat[nth][ntr][ntc] = mat[th][tr][tc]+1; // this is important!!
                q.push({nth,ntr,ntc});
            }
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> m >> n >> h;int temp;
    for(int p=0;p<h;p++){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> temp;mat[p][i][j]=temp;
                if(temp==1){
                    q.push({p,i,j});
                }
            }
        }
    }
    BFS();
    int maxi = 0;
    for(int p=0;p<h;p++){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[p][i][j] == 0){
                    cout << -1;return 0;
                }else{
                    if(mat[p][i][j] > maxi){
                        maxi=mat[p][i][j];
                    }
                }
            }
        }

    }
    cout << maxi-1;
    
}