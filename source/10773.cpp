#include <bits/stdc++.h>
using namespace std;

stack<int> s;
int k;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>k;
	for(int i=0;i<k;i++){
		int l;cin>>l;
		if(l == 0){
			s.pop();
		}else{
			s.push(l);
		}
	}
	int sum=0;
	while(!s.empty()){
		sum+=s.top();
		s.pop();
	}
	cout << sum;
}