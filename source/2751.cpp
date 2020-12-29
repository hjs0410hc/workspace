#include <bits/stdc++.h>
using namespace std;

priority_queue<int,vector<int>,greater<int>> pq;
int n,p;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	while(n--){
		cin>>p;
		pq.push(p);
	}
	while(!pq.empty()){
		cout << pq.top() << "\n";
		pq.pop();
	}
	
	
}