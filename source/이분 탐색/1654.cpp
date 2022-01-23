#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
int K,N;
vector<ll> v;


ll UTPS(ll x){
	ll ret = 0;
	if(x != 0){
		for(auto w:v){
			ret += w/x;
		}
	}
	return ret;
}

ll binary_search(){
	ll start = 1;
	ll end = INT32_MAX;
	while(start <= end){
		ll middle = (start+end)/2;
		ll utps = UTPS(middle);
		if(utps >= N){
			start = middle+1;
		}else if(utps < N){
			end = middle-1;
		}
	}
	//cout << start << " " << end;
	return end;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> K >> N;
	for(int i=0;i<K;i++){
		int k;cin>>k;
		v.push_back(k);
	}
	int ans = binary_search();
	cout << ans;
	/* while(UTPS(ans) == N){
		ans++;
	}
	cout << --ans; */
	
}