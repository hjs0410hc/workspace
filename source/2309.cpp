#include <bits/stdc++.h>
using namespace std;

vector<int> v;
vector<int> m{0,0,1,1,1,1,1,1,1};

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	for(int i=0;i<9;i++){
		int k;cin>>k;
		v.push_back(k);
	}
	do{
		int sum = 0;
		priority_queue<int,vector<int>,greater<int>> pq;
		for(int i=0;i<9;i++){
			if(m[i]==1){
				sum+=v[i];
				pq.push(v[i]);
			}
		}
		if(sum==100){
			while(!pq.empty()){
				cout << pq.top() << "\n";
				pq.pop();
			}
			return 0;
		}
	}while(next_permutation(m.begin(),m.end()));
	
	
}