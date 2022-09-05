#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll mat[101][10]; // 몇번째 자리에서 해당 수가 몇개 있는가?

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    for(int i=1;i<10;i++){
        mat[1][i]++;
    }
    for(int j=2;j<101;j++){
        for(int i=0;i<10;i++){
            if(i==0){ // 1에서밖에 못온다
                mat[j][i] = mat[j-1][1] % 1000000000ll;
            }else
            if(i==9){ // 8에서밖에 못온다.
                mat[j][i] = mat[j-1][8] % 1000000000ll;
            }else
            mat[j][i] = (mat[j-1][i-1] + mat[j-1][i+1]) % 1000000000ll;
        }
    }
    int n;cin>>n;
    int ans = 0;
    for(int i=0;i<10;i++){
        ans += mat[n][i];
        ans %= 1000000000ll;
    }
    cout << ans;
    
    
    
}