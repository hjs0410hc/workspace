#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n; // 분해합.
    // 어떤 수 k의 분해합이 n이 되면 k는 n의 생성자. 가장 작은 k를 찾으시오...
    int org = n;
    int temp = n;
    int digit = 0;
    while(temp > 0){
        temp /= 10;
        digit++;
    }
    int i = org - 9*digit;
    bool found = false;
    int ans;
    for(i;i<=n;i++){
        int k=i; // 분해합이 될 아이
        int calc=i; // 0 이 될 불쌍한 아이
        while(calc > 0){
            k += calc % 10;
            calc /= 10;
        }
        if(k == n){
            ans = i;
            found = true;
            break;
        }
    }
    if(found){
        cout << ans;
    }else{
        cout << 0;
    }
}