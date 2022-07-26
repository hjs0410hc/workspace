#include <bits/stdc++.h>
using namespace std;



int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,x;cin>>n;
    int ans = 0;
    int nums[n+1];
    int dp[n+1];

    for(int i=1;i<=n;i++){
        cin >> nums[i];
    }
    ans = dp[1] = nums[1];
    for(int i=2;i<=n;i++){
        if(nums[i] > dp[i-1]+nums[i]){
            dp[i] = nums[i];
        }else{
            dp[i] = dp[i-1]+nums[i];
        }
        ans = max(ans,dp[i]);
    }
    cout << ans;
    
    
}
