#include <bits/stdc++.h>
using namespace std;

int m,n;

bool mat[10001]; // 1이면 소수아님, 0이면 소수.
int ans = 0;


int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    memset(mat,0,sizeof(mat));
    mat[0]=1;
    mat[1]=1;
    for(int i=2;i<10001;i++){
        for(int j=2;j*i<10001;j++){
            mat[j*i] = 1;
        }
    }
    cin >> m >>n;
    int mini = 2e9;
    for(int i=m;i<=n;i++){
        if(mat[i] == 0){
            if(mini>i){
                mini = i;
            }
            ans += i;
        }
    }
    if(mini == 2e9){
        cout << -1;
    }else{

        cout << ans <<"\n"<< mini;
    }
}