#include <bits/stdc++.h>
using namespace std;

int N,M; // row가 N // col이 M.

int arr[101][101];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
bool checked[101][101];
int dist[101][101];

void BFS(){
	priority_queue<pair<int,pair<int,int> > > pq;
	dist[1][1] = 0;
	pq.push({0,{1,1}});
	while(!pq.empty()){
		int cw = -pq.top().first;
		pair<int,int> cpos = pq.top().second;
		pq.pop();
		checked[cpos.first][cpos.second]=true;
		for(int i=0;i<4;i++){
			int nx = cpos.first + dx[i];
			int ny = cpos.second + dy[i];
			if(nx > 0 && ny > 0 && nx <= N && ny <= M && !checked[nx][ny]){
				if(dist[nx][ny] > cw + arr[nx][ny]){
					dist[nx][ny] = cw + arr[nx][ny];
					pq.push({-dist[nx][ny],{nx,ny}});
				}
			}
		}
	}
}


int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	for(int i=0;i<101;i++){
		for(int j=0;j<101;j++){
			dist[i][j]=2e9;
		}
	}
	cin>>M>>N;
	for(int i=1;i<=N;i++){
		string s;cin>>s;
		for(int j=1;j<=M;j++){
			arr[i][j] = s[j-1]-'0';
		}
	}
	memset(checked,0,sizeof(checked));
	BFS();
	cout << dist[N][M];
	
}