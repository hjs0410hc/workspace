#include <bits/stdc++.h>
using namespace std;

int arr[1001][1001];
int n,r,c;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> r>> c;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin >> arr[i][j];
		}
	}
	int me = arr[r][c];
	bool flag = false;
	for(int i=1;i<=n;i++){
		if(arr[r][i] > me && i != c){
			flag = true;
			break;
		}
	}
	if(flag){
		cout << "ANGRY";
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(arr[i][c] > me && i != r){
			flag = true;
			break;
		}
	}
	if(flag){
		cout << "ANGRY";
		return 0;
	}
	if(!flag){
		cout << "HAPPY";
		return 0;
	}
}