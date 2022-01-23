#include <bits/stdc++.h>
using namespace std;

int n,p,i;
string s;
vector<string> v[201];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n;
	for(i=0;i<n;i++){
		cin >> p >> s;
		v[p].push_back(s);
	}
	for(int i=0;i<201;i++){
		if(!v[i].empty()){
			for(auto w:v[i]){
				cout << i << " " << w << "\n";
			}
		}
	}
	

	
	
}