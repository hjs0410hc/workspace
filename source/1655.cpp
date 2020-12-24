#include <bits/stdc++.h>
using namespace std;
int n,p,s,t1,t2;
priority_queue<int,vector<int>> maxpq;
priority_queue<int,vector<int>,greater<int>> minpq;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	while(n--){
		cin >> p;
		if(maxpq.empty()){
			maxpq.push(p);
		}else if(maxpq.size() > minpq.size()){
			minpq.push(p);
		}else if(maxpq.size() < minpq.size()){
			maxpq.push(p);
		}else{
			maxpq.push(p);
		}
		if(!maxpq.empty() && !minpq.empty()){
			t1=maxpq.top();t2=minpq.top();
			if(t1 > t2){
				maxpq.pop();
				minpq.pop();
				maxpq.push(t2);
				minpq.push(t1);
			}
		}

		cout << maxpq.top() << "\n";
	}
}