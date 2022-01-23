#include <bits/stdc++.h>
using namespace std;

int mat[15][15];
int tc;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    memset(mat,0,sizeof(mat));
    for(int i=1;i<=14;i++){
        mat[0][i] = i;
    }
    for(int i=1;i<=14;i++){
        int sum = 0;
        for(int j=1;j<=14;j++){
            sum += mat[i-1][j];
            mat[i][j] = sum;
        }
    }
    cin >> tc;
    while(tc--){
        int k,n;cin>>k>>n;
        cout << mat[k][n] << "\n";
        
    }
    
    
}