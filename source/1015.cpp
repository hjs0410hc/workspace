#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> v;
int N;

bool comp(pair<int,int>& p1, pair<int,int>& p2){
	if(p1.second == p2.second){
		return p1.first < p2.first;
	}
	return p1.second < p2.second;
}


int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> N;
	for(int i=0;i<N;i++){
		int k;cin>>k;
		v.push_back({i,k});
	}
	vector<int> s(N);
	sort(v.begin(),v.end(),comp);
	int i= 0;
	for(auto p:v){
		s[p.first] = i++;
	}
	for(auto w:s){
		cout << w << " ";
	}
}