#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ll;

ll dp[101][101]; // low 17 digits
ll dp2[101][101]; // high 17digits


int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    memset(dp,0,sizeof(dp));
    memset(dp2,0,sizeof(dp));
    dp[1][1] = 1;
    for(int i=0;i<101;i++){
        dp[i][0] = 1;
    }
    for(int i=2;i<101;i++){
        for(int j=1;j<=i;j++){
            dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
            dp2[i][j] = dp2[i-1][j-1]+dp2[i-1][j];
            if(dp[i][j] >= (ll)pow(10,16)){
                dp2[i][j] += (dp[i][j]/(ll)pow(10,16));
                dp[i][j]%=(ll)pow(10,16);
            }
        }
    }
    int n,r;
    cin >> n >> r;
    if(dp2[n][r]){
        cout << dp2[n][r] << setfill('0') << setw(16) << dp[n][r];
    }else{
        cout <<  dp[n][r];
    }
    
    
}