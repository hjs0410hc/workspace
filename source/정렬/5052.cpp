#include <bits/stdc++.h>
using namespace std;

bool isitFullyCross(string& s1,string& s2){ // s2 must be longer than s1.
	for(int i=1;i<=s2.size();i++){
		if(s2.substr(0,i) == s1){
			return true;
		}
	}
	return false;
}


int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--){
		vector<string> v;
		int n;cin>>n;
		for(int i=0;i<n;i++){
			string s;cin>>s;
			v.push_back(s);
		}
		sort(v.begin(),v.end());
		bool flag = false;
		for(int i=0;i<v.size()-1;i++){
			if(isitFullyCross(v[i],v[i+1])){
				flag=true;
				break;
			}
		}
		cout << ((flag) ?"NO" :"YES") << "\n";
	}
	
}