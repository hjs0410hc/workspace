#include <bits/stdc++.h>
using namespace std;



int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    int stairs[n+1];
    int dp[n+1];
    for(int i=0;i<n;i++){
        cin>>stairs[i];
    }
    dp[0]=stairs[0];
    dp[1]=stairs[0]+stairs[1];
    dp[2]=max(stairs[1]+stairs[2],stairs[0]+stairs[2]);
    //dp[N] = dp[N-2]+stairs[N] or dp[N-3]+stairs[N-1]+stairs[N]
    for(int i=3;i<n;i++){
        dp[i] = max(dp[i-2]+stairs[i],dp[i-3]+stairs[i-1]+stairs[i]);
    }
    cout << dp[n-1];
    
    
}