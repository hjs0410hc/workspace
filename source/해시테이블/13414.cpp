#include <bits/stdc++.h>
using namespace std;

unordered_map<string,int> m;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int k,l;cin>>k>>l;
	int waiting = 0;
	vector<string> v;
	vector<string> v2;
	for(int i=0;i<l;i++){
		string c;cin>>c;
		v.push_back(c);
		m[c] = waiting++;
	}
	for(int i=0;i<v.size();i++){
		if(i == m[v[i]]){ // genius
			v2.push_back(v[i]);
		}
	}
	for(int i=0;i<((k > v2.size()) ? v2.size() : k);i++){
		cout << v2[i] << "\n";
	}
}