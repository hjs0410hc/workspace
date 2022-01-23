#include <bits/stdc++.h>
using namespace std;

bool comparator(string s1,string s2){
	if(s1.length() == s2.length()){
		return s1 < s2;
	}else{
		return s1.length() < s2.length();
	}
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n;cin>>n;
	vector<string> v;
	while(n--){
		string s;cin>>s;
		v.push_back(s);
	}
	sort(v.begin(),v.end(),comparator);
	v.erase(unique(v.begin(),v.end()),v.end());
	for(string s:v){
		cout << s << "\n";
	}
}