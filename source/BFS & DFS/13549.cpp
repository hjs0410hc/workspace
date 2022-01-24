#include <bits/stdc++.h>
using namespace std;



bool arr[100001];

int n,k;
int ans = 2e9;
int ans2 = 0;


void BFS(){
	queue<int> q;
	queue<int> num;
	arr[n]=true;
	q.push(n);
	num.push(0);
	while(!q.empty()){
		int f = q.front();
		int nb = num.front();
		arr[f]=true;
		q.pop();
		num.pop();
		if(f==k){
			if(ans!=min(ans,nb)){ // ans가 바뀌는 경우
				ans = min(ans,nb);
				ans2=1;
			}else if(nb==ans){
				ans2++;
			}
		}
		if(2*f < 100001 && !arr[2*f]){
			//arr[2*f]=true;
			q.push(2*f);
			num.push(nb);
		}
		if(f+1 < 100001 && !arr[f+1]){
			//arr[f+1]=true;
			q.push(f+1);
			num.push(nb+1);
		}
		if(f-1 >= 0 && !arr[f-1]){
			//arr[f-1]=true;
			q.push(f-1);
			num.push(nb+1);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> k;
	BFS();
	cout << ans;
	
	
}