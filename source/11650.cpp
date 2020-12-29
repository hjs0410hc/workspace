#include <bits/stdc++.h>
using namespace std;

int n,p,q;
vector<pair<int,int>> v;
bool comparator(pair<int,int>& p1, pair<int,int>& p2){
	if(p1.first == p2.first){
		return p1.second < p2.second;
	}
	return p1.first<p2.first;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>p>>q;
		v.push_back({p,q});
	}
	sort(v.begin(),v.end(),comparator);
	for(pair<int,int> p:v){
		cout << p.first << " " << p.second << "\n";
	}
	
}