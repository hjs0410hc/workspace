#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;


int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		v.push_back(i+1);
	}
	do{
		for(auto w:v){
			cout << w << " ";
		}
		cout << "\n";
	}while(next_permutation(v.begin(),v.end()));
}