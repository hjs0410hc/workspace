#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll arr[501][501];
pair<int,int> target;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n;cin>>n;	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int k;cin>>k;
			arr[i][j] = k;
			if(k==0){
			target.first = i;
			target.second = j;
			}
		}
	}
	ll sum1 = 0;
	int sum1chg = 0;
	// 규칙 1. 같은 행의 수 합.
	for(int i=1;i<=n;i++){
		ll sum = 0;
		if(i==target.first){
			continue;
		}
		for(int j=1;j<=n;j++){
			sum+= arr[i][j];
		}
		if(sum!=sum1){
			sum1=sum;
			sum1chg++; // sum1chg는 무조건 1이어야한다.
		}
	}
	if(sum1chg > 1){
		cout << -1; return 0;
	}
	ll sum2 = 0;
	int sum2chg = 0;
	for(int i=1;i<=n;i++){
		ll sum=0;
		if(i==target.second){
			continue;
		}
		for(int j=1;j<=n;j++){
			sum += arr[j][i];
		}
		if(sum!=sum2){
			sum2=sum;
			sum2chg++;
		}
	}
	if(sum2chg > 1){
		cout << -1; return 0;
	}
	if(sum1 != sum2){
		cout << -1; return 0;
	}
	//규칙1check
	ll firstsum = 0;
	for(int i=1;i<=n;i++){
		firstsum+= arr[target.first][i];
	}
	//규칙2check
	ll secondsum = 0;
	for(int i=1;i<=n;i++){
		secondsum += arr[i][target.second];
	}
	if(firstsum != secondsum){
		cout << -1; return 0;
	}
	ll middlecheck = sum1-firstsum;
	arr[target.first][target.second] = middlecheck;
	int i{1},j{1};
	ll rsum=0;
	ll rsum2=0;
	while(i<=n){
		rsum+=arr[i][j];
		i++;j++;
	}
	i=1;j=-i+n+1;
	while(i<=n){
		rsum2+=arr[i][j];
		i++;j=-i+n+1;
	}
	if(rsum!=rsum2){
		cout << -1;return 0;
	}else{
		if(rsum != sum1){
			cout << -1;return 0;
		}else{
			cout << arr[target.first][target.second];
		}
	}



}