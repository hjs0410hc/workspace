#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll ans[10];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    memset(ans,0,sizeof(ans));
    ll n;cin>>n;
    ll temp = n;
    int digit = 0;
    while(temp > 0){
        temp /= 10L;
        digit++;
    }
    int prev = 0;
    for(int i=digit-1;i>=0;i--){
        int k = (n / (ll)(pow(10,i))) % 10L;
        for(int j=9;j>=0;j--){
            if(j>k){
                ans[j] += prev*pow(10,i);
            }else if(j==k){
                if(j==0){
                    ans[j] += (n%((ll)pow(10,i)))+1+(prev-1)*pow(10,i);
                }else{
                    ans[j] += (n%((ll)pow(10,i)))+1+prev*pow(10,i);
                }
            }else if(j==0){
                ans[j] += prev*pow(10,i);
            }
            else if(j<k){
                ans[j] += (prev+1)*pow(10,i);
            }
        }
        prev *= 10;
        prev += k;
    }
    for(int i=0;i<10;i++){
        cout << ans[i] << " ";
    }
}