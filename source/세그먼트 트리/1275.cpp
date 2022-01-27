#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll arr[100001];
ll tree[400005];

ll init(ll start,ll end,ll node){
    if(start==end){
        return tree[node] = arr[start];
    }
    ll mid = (start+end)/2;
    return tree[node] = init(start,mid,node*2)+init(mid+1,end,node*2+1);
}

ll sum(ll start,ll end,ll node,ll left,ll right){
    if(left > end || right < start) return 0;
    if(left <= start && end <= right) return tree[node];
    ll mid = (start+end)/2;
    return sum(start,mid,node*2,left,right)+sum(mid+1,end,node*2+1,left,right);
}

void update(ll start,ll end,ll node,ll index,ll dif){
    if(index<start || index>end)return;
    tree[node] += dif;
    if(start==end)return;
    ll mid=(start+end)/2;
    update(start,mid,node*2,index,dif);
    update(mid+1,end,node*2+1,index,dif);
}
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
        cin >> x >>y >> a>>b;
        if(x>y){
            swap(x,y);
        }
        cout << sum(0,n-1,1,x-1,y-1) << "\n";
        update(0,n-1,1,a-1,b-arr[a-1]);
        arr[a-1] = b;
    }
    
}