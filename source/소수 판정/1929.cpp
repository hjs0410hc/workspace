#include <bits/stdc++.h>
using namespace std;

int mat[1000001];
int m,n;
int ans = 0;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    memset(mat,0,sizeof(mat));
    mat[0] = -1;
    mat[1] = -1;
    for(int i=2;i<1000001;i++){
        if(mat[i] == -1){
            continue;
        }else{
            // mat[i] != -1인 경우 그것은 소수당
            for(int j=2;i*j<1000001;j++){
                mat[i*j] = -1;
            }
        }
    }
    cin >> m >> n;
    for(int i=m;i<=n;i++){
        if(mat[i] == 0){
            cout << i << "\n";
        }
    }

} 