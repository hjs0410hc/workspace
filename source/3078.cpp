#include <bits/stdc++.h>
using namespace std;

queue<int> q[21];
long long int ans = 0;



int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int N,K;cin>>N>>K;
	for(int i=1;i<=N;i++){
		string s;cin>>s;
		int length = s.length();
		while(!q[length].empty() && i - q[length].front() > K){
			q[length].pop();
		}
		ans += q[length].size();
		q[length].push(i);
	}
	cout << ans;
}