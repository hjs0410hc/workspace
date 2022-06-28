#include <bits/stdc++.h>
using namespace std;

int a,b,c;
int dp[21][21][21];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    for(int i=0;i<21;i++){ // A
        for(int j=0;j<21;j++){ // B
            for(int k=0;k<21;k++){ // C
                dp[i][j][k] = 1;
            }
        }
    }    
    for(int i=1;i<21;i++){ // A
        for(int j=1;j<21;j++){ // B
            for(int k=1;k<21;k++){ // C
                if(i<j && j<k){
                    dp[i][j][k] = dp[i][j][k-1] + dp[i][j-1][k-1] - dp[i][j-1][k];
                }else{
                    dp[i][j][k] = dp[i-1][j][k] + dp[i-1][j-1][k] + dp[i-1][j][k-1] - dp[i-1][j-1][k-1];
                }
            }
        }
    }
    while(true){
        cin >> a >> b >> c;
        if(a==-1 && b==-1 && c==-1){
            break;
        }else if(a <= 0 || b <= 0 || c <= 0){
            cout << "w(" << a << ", " << b << ", " << c << ") = " << 1 << '\n';
        }else if(a > 20 || b > 20 || c > 20){
            cout << "w(" << a << ", " << b << ", " << c << ") = " << dp[20][20][20] << '\n';
        }else{
            cout << "w(" << a << ", " << b << ", " << c << ") = " << dp[a][b][c] << '\n';
        }
    }
    
    
}