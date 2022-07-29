#include <bits/stdc++.h>
using namespace std;
#define NUMBER 1000001
int dp[NUMBER];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    for(int i=4;i<NUMBER;i++){
        dp[i] = 20000000;
        if(i%2==0){
            dp[i] = dp[2]+dp[i/2];
        }
        if(i%3==0){
            dp[i] = min(dp[i/3]+dp[3],dp[i]);
        }
        dp[i] = min(dp[i], dp[i-1]+1);
    }
    int x;cin>>x;
    cout << dp[x];
    
    
}