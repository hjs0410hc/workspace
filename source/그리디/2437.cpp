#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int n;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		int k;cin>>k;
		v.push_back(k);
	}
	sort(v.begin(),v.end());
	int presum = 0;
	for(int i=0;i<n;i++){
		if(presum+1 < v[i]){
			cout << presum+1;
			return 0;
		}else{
			presum+= v[i];
		}
	}
	cout << presum+1;
}