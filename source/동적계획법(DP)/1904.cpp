#include <bits/stdc++.h>
using namespace std;

int n;
typedef long long int ll;

ll dp[1000001];


int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3;i<1000001;i++){
        dp[i] = (dp[i-2] + dp[i-1])%15746;
    }
    cin >>n;
    cout << dp[n]%15746;
    
    
    
}