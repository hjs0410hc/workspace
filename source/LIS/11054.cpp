#include <bits/stdc++.h>
using namespace std;

int n,ans{0};
int ARR[1001],dp[1001],dp2[1001];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n;
    dp[0] = 0;
    dp2[n-1] = 0;
    for(int i=0;i<n;i++){
        cin >> ARR[i];
    }
    for(int i=0;i<n;i++){ // 왼쪽부터 LIS
        int len = 0;
        for(int j=0;j<i;j++){
            if(ARR[i] > ARR[j]){
                len = max(len,dp[j]);
            }
        }
        dp[i] = len + 1;
    }
    for(int i=n-1;i>=0;i--){ // 오른쪽부터 LIS
        int len = 0;
        for(int j=n-1;j>i;j--){
            if(ARR[i] > ARR[j]){
                len = max(len,dp2[j]);
            }
        }
        dp2[i] = len + 1;
    }
    for(int i=0;i<n;i++){
        ans = max(ans,dp[i]+dp2[i]);
    }
    cout << ans-1;
}