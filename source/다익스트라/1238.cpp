#include <bits/stdc++.h>
using namespace std;

int n,m,x,a,b,c;
int cost[1001][1001];
int d[1001][1001];

void floydWarshall(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            d[i][j] = cost[i][j];
        }
    }

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(d[i][k]+d[k][j] < d[i][j]){
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >>n>>m>>x;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                cost[i][j]=0;
            }else{
                cost[i][j]=156512;
            }
        }
    }
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        cost[a-1][b-1]=c;
    }
    floydWarshall();
    int max1{0};
    // i -> X + X -> i
    for(int i=0;i<n;i++){
        max1 = max(max1,d[i][x-1]+d[x-1][i]);
    }
    cout << max1;
}