#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll arr[100001];
ll tree[400005];
ll tree2[400005];

//segment tree that finds min and max... do we require 2 segment trees?
ll init(ll start,ll end,ll node){
    if(start==end){
        return tree[node] = arr[start];
    }
    ll mid = (start+end)/2;
    return tree[node] = min(init(start,mid,node*2),init(mid+1,end,node*2+1));
}

ll query(ll start,ll end,ll node,ll left,ll right){
    if(left > end || right < start) return 2e15;
    if(left <= start && end <= right) return tree[node];
    ll mid = (start+end)/2;
    return min(query(start,mid,node*2,left,right),query(mid+1,end,node*2+1,left,right));
}
// we don't do that here. - by black panther -
/* void update(ll start,ll end,ll node,ll index,ll dif){
    if(index<start || index>end)return;
    tree[node] += dif;
    if(start==end)return;
    ll mid=(start+end)/2;
    update(start,mid,node*2,index,dif);
    update(mid+1,end,node*2+1,index,dif);
} */

ll n,q,x,y,a,b;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n>>q;
    for(ll i=0;i<n;i++){
        cin >> x;
        arr[i] = x;
    }
    init(0,n-1,1);
    for(ll i=0;i<q;i++){
        cin >> x >>y;
        if(x>y){
            swap(x,y);
        }
        cout << query(0,n-1,1,x-1,y-1) << "\n";
    }
    
}