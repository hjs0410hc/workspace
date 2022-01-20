#include <bits/stdc++.h>
using namespace std;

int n,ans{0};
int ARR[1001],dp[1001];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n;
    dp[0] = 0;
    for(int i=0;i<n;i++){
        cin >> ARR[i];
        int len = 0;
        for(int j=0;j<i;j++){
            if(ARR[i] > ARR[j]){
                len = max(len,dp[j]); //perfect;;;
            }
        }
        dp[i] = len + 1;
        ans = max(ans,dp[i]);
    }
    cout << ans;
}