#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    if(n==1){
        cout << 1; return 0;
    }else{
        int calc = 0;
        int i = 2;
        int ans = 1;
        while(calc < n){
            calc = 3*i*(i-1)+1;
            i++;
            ans++;
        }
        cout << ans;
    }
    
}