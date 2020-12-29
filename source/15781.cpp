#include <bits/stdc++.h>
using namespace std;

int N,M,k;
priority_queue<int,vector<int>> hq;
priority_queue<int,vector<int>> jq;



int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> N>> M;
	for(int i=0;i<N;i++){
		cin>>k;
		hq.push(k);
	}
	for(int i=0;i<M;i++){
		cin>>k;
		jq.push(k);
	}
	cout << hq.top()+jq.top();
	
}