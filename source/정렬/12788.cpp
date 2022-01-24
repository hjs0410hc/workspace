#include <bits/stdc++.h>
using namespace std;

priority_queue<int,vector<int>> pq;
int n,m,k;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=0;i<n;i++){
		int p;cin>>p;
		pq.push(p);
	}
	int reqpen = m*k;
	int ans = 0;
	while(reqpen > 0){
		if(pq.empty()){
			cout << "STRESS";
			return 0;
		}
		reqpen -= pq.top();
		pq.pop();
		ans++;
	}
	cout << ans;
}
