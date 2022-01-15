#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll triCross(pair<ll,ll>& p1,pair<ll,ll>& p2,pair<ll,ll>& p3){
    ll a = (p2.first-p1.first)*(p3.second-p2.second)-(p3.first-p2.first)*(p2.second-p1.second);
    if(a>0){
        return 1;
    }else if(a==0){
        return 0;
    }else{
        return -1;
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll x_1,y_1,x_2,y_2,x_3,y_3,x_4,y_4;
    cin >> x_1 >> y_1 >> x_2 >> y_2 >> x_3 >> y_3 >> x_4 >> y_4;
    pair<ll,ll> p1 ={x_1,y_1};
    pair<ll,ll> p2 ={x_2,y_2};
    pair<ll,ll> p3 ={x_3,y_3};
    pair<ll,ll> p4 ={x_4,y_4};
    
    int k=triCross(p1,p2,p3)*triCross(p1,p2,p4);
    int p=triCross(p3,p4,p1)*triCross(p3,p4,p2);

    if(k < 0 && p < 0){
        cout << 1;
    }else{
        cout << 0;
    }
    
    
}