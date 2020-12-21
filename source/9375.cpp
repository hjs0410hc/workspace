#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int tc;cin>>tc;
	while(tc--){
		int n;cin>>n;
		unordered_map<string,int> m;
		vector<string> vs;
		for(int i=0;i<n;i++){
			string s1,s2;cin>>s1>>s2;
			vs.push_back(s2);
			m[s2]++;
		}
		sort(vs.begin(),vs.end());
		vs.erase(unique(vs.begin(),vs.end()),vs.end());

		int ans = 1;
		for(string s:vs){
			ans *= (m[s]+1);
		}
		ans--;
		cout << ans << "\n";
	}
	
}