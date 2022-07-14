#include <bits/stdc++.h>
using namespace std;

long long int dp[101];
int t,k;


int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    for(int i=5;i<101;i++){
        dp[i] = dp[i-2]+dp[i-3];
    }
    cin>>t;
    while(t--){
        cin >> k;
        cout << dp[k] << '\n';
    }
}