#include <bits/stdc++.h>
using namespace std;

queue<int> q;
vector<int> v;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,k;cin>>n>>k;
	for(int i=1;i<=n;i++){
		q.push(i);
	}
	while(!q.empty()){
		for(int i=0;i<k-1;i++){
			q.push(q.front());
			q.pop();
		}
		v.push_back(q.front());
		q.pop();
	}
	cout << "<";
	for(int i=0;i<v.size()-1;i++){
		cout << v[i] << ", ";
	}
	cout << *(v.end()-1) << ">";
}