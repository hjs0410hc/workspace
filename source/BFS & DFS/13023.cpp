#include <bits/stdc++.h>
using namespace std;

vector<int> graph[2001];
bool visited[2001];
int ans = 0;


void DFS(int s, int k){
	if(k>=5){
		ans = 1;
		return;
	}
	visited[s]=true;
	for(int w:graph[s]){
		if(!visited[w]){
			DFS(w,k+1);
		}
		if(ans==1)return;
	}
	visited[s]=false;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=0;i<m;i++){
		int s,d;cin>>s>>d;
		graph[s].push_back(d);
		graph[d].push_back(s);
	}
	for(int i=0;i<n;i++){
		memset(visited,0,sizeof(visited));
		DFS(i,1);
		if(ans==1){
			break;
		}
	}
	cout << ans;
	
}