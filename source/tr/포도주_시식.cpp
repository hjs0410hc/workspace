#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    int ans = 0;
    int mat[n+1];
    int dp[n+1];
    for(int i=1;i<=n;i++){
        cin >> mat[i];
    }
    if(n==1){
        ans = mat[1];
    }else if(n==2){
        ans = mat[1]+mat[2];
    }else{
        dp[0] = mat[0] = 0;
        dp[1] = mat[1];
        dp[2] = mat[1]+mat[2];
        for(int i=3;i<=n;i++){
            dp[i] = max(dp[i-3]+mat[i-1]+mat[i],dp[i-2]+mat[i]);
            dp[i] = max(dp[i],dp[i-1]);
            ans = max(dp[i],ans);
        }
    }



    cout << ans;
}