#include <bits/stdc++.h>
using namespace std;



int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,x;cin>>n;   
    int dp[n][3];
    int mat[n][3];

    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin >> mat[i][j];
        }
    }
    for(int i=0;i<3;i++){
        dp[0][i] = mat[0][i];
    }    // (0,0), (0,1), (0,2) INIT'D.
    
    for(int i=1;i<n;i++){
        for(int j=0;j<3;j++){
            if(j==0){ //1,2
                dp[i][j] = min(dp[i-1][1],dp[i-1][2])+mat[i][j];
            }else if(j==1){ //0,2
                dp[i][j] = min(dp[i-1][0],dp[i-1][2])+mat[i][j];
            }else if(j==2){ //0,1
                dp[i][j] = min(dp[i-1][1],dp[i-1][0])+mat[i][j];
            }
        }
    }
    int ans = 2e9;
    for(int i=0;i<3;i++){
        ans = min(ans,dp[n-1][i]);
    }
    cout << ans;
    
}