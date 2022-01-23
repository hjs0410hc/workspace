#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> v;
int ans = 0;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin  >> n>>m;
	for(int i=0;i<n;i++){
		int k;cin>>k;
		v.push_back(k);
	}
	for(int i=0;i<v.size()-2;i++){
		for(int j=i+1;j<v.size()-1;j++){
			for(int p=j+1;p<v.size();p++){
				int sum = v[i]+v[j]+v[p];
				if(sum <= m){
					ans = max(ans,sum);
				}
			}
		}
	}
	cout << ans;
	
}