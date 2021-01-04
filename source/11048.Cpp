#include <bits/stdc++.h>
using namespace std;

int N,M;
int mapm[1001][1001];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	memset(mapm,0,sizeof(mapm));
	cin >> N>>M;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			cin >> mapm[i][j];
			mapm[i][j] += max({mapm[i-1][j],mapm[i][j-1],mapm[i-1][j-1]});
		}
	}
	
	cout << mapm[N][M];
}