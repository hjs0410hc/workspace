#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
priority_queue<int,vector<int>> pluspq;
priority_queue<int,vector<int>,greater<int>> negpq;



int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=0;i<n;i++){
		int k;cin>>k;
		if(k>0){
			pluspq.push(k);
		}else if(k<=0){
			negpq.push(k);
		}
	}
	ll sum = 0;
	while(pluspq.size() > 1){
		int i1,i2;
		i1=pluspq.top();
		pluspq.pop();
		i2=pluspq.top();
		pluspq.pop();
		if(i2==1){
			sum += (i1+i2);
		}else{
			sum += (i1*i2);
		}
	}
	if(pluspq.size()==1){
		sum += pluspq.top();
		pluspq.pop();
	}
	while(negpq.size() > 1){
		int i1,i2;
		i1=negpq.top();
		negpq.pop();
		i2=negpq.top();
		negpq.pop();
		sum += (i1*i2);
	}
	if(negpq.size() == 1){
		sum += negpq.top();
		negpq.pop();
	}
	cout << sum;
}