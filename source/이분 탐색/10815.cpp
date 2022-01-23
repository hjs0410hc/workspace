#include <bits/stdc++.h>
using namespace std;

bool arr[20000001];
// -10000000 : 0
// 10000000: 20000000
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	memset(arr,0,sizeof(arr));
	int n;cin>>n;
	for(int i=0;i<n;i++){
		int k;cin>>k;
		arr[k+10000000] = true;
	}
	int m;cin>>m;
	for(int i=0;i<m;i++){
		int k;cin>>k;
		int idx = k+10000000;
		if(arr[idx]){
			cout << 1 << " ";
		}else{
			cout << 0 << " ";
		}
	}
	
	
}