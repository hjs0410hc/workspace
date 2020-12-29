#include <bits/stdc++.h>
using namespace std;

int arr[10001];
int n,k;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	memset(arr,0,sizeof(arr));
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>k;
		arr[k]++;
	}
	for(int i=1;i<=10000;i++){
		if(arr[i] != 0){
			for(int j=0;j<arr[i];j++){
				cout << i << "\n";
			}
		}
	}
	
	
}