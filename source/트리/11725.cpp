#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> graph[100001];
bool visited[100001];
int answer[100001];

void BFS(){
	queue<int> q;
	visited[1] = true;
	q.push(1);
	while(!q.empty()){
		int f = q.front();
		q.pop();
		for(int w:graph[f]){
			if(!visited[w]){
				answer[w] = f;
				visited[w]=true;
				q.push(w);
			}
		}
	}
}



int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	memset(visited,0,sizeof(visited));
	memset(answer,0,sizeof(answer));
	cin >> n;
	for(int i=0;i<n-1;i++){
		int s,d;cin >>s >>d;
		graph[s].push_back(d);
		graph[d].push_back(s);
	}
	BFS();
	for(int i=2;i<=n;i++){
		cout << answer[i] << "\n";
	}
}