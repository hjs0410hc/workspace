#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll> v;

ll gcd(ll a,ll b){
    ll n;
    while(b!=0){
        n=a%b;
        a=b;
        b=n;
    }
    return a;
}

ll lcm(ll a,ll b){
    return a*b/gcd(a,b);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int x;
    ll mini = 2e9;
    for(int i=0;i<5;i++){
        cin >> x;
        v.push_back(x);
    }
    for(int i=0;i<5;i++){
        for(int j=i+1;j<5;j++){
            for(int k=j+1;k<5;k++){
                mini = min(mini,lcm(lcm(v[i],v[j]),v[k]));
            }
        }
    }
    for(int i=0;i<5;i++){
        for(int j=i+1;j<5;j++){
            for(int k=j+1;k<5;k++){
                for(int p=k+1;p<5;p++){
                    mini = min(mini,lcm(lcm(lcm(v[i],v[j]),v[k]),v[p]));
                }
            }
        }
    }
    mini=min(mini,lcm(lcm(lcm(lcm(v[0],v[1]),v[2]),v[3]),v[4]));
    cout << mini;
}