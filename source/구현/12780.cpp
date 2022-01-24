#include <bits/stdc++.h>
using namespace std;

string h,n;
int ans = 0;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>h>>n;
	for(int i=0;i<h.length()-n.length()+1;i++){
		if(h.substr(i,n.length())==n){
			ans++;
		}
	}
	cout << ans;
	
}
