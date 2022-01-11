#include <bits/stdc++.h>
using namespace std;

int mat[1001];
int ans = 0;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    memset(mat,0,sizeof(mat));
    mat[0] = -1;
    mat[1] = -1;
    for(int i=2;i<1001;i++){
        if(mat[i] == -1){
            continue;
        }else{
            // mat[i] != -1인 경우 그것은 소수당
            for(int j=2;i*j<1001;j++){
                mat[i*j] = -1;
            }
        }
    }

    int n,k;cin>>n;
    for(int i=0;i<n;i++){
        cin >> k;
        if(mat[k] == 0){
            ans++;
        }
    }
    cout << ans;
}