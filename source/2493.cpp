#include <bits/stdc++.h>
using namespace std;

stack<pair<int,int>> st;
int ans[500001];
int n;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i=0;i<n;i++){
		int k;cin>>k;
		if(st.empty()){
			ans[i] = 0;
		}else{
			while(!st.empty() && st.top().second < k){
				st.pop();
			}
			ans[i] = ((st.empty())?0:st.top().first);
		}
		st.push({i+1,k});
	}
	for(int i=0;i<n;i++){
		cout << ans[i] << " ";
	}
}