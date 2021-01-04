#include <bits/stdc++.h>
using namespace std;

int N,M,X,Y,T,C;
vector<int> graph[100001];
vector<int> rgraph[100001];
bool visited[100001];
bool can1go[100001];
bool canngo[100001];

void DFS(int x){
	visited[x] = true;
	can1go[x] = true;
	for(int w:graph[x]){
		if(!visited[w]){
			DFS(w);
		}
	}
}


void rDFS(int x){
	visited[x] = true;
	canngo[x] = true;
	for(int w:rgraph[x]){
		if(!visited[w]){
			rDFS(w);
		}
	}
}



int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>N>>M;
	for(int i=0;i<M;i++){
		cin >> X>>Y;
		graph[X].push_back(Y);
		rgraph[Y].push_back(X);
	}
	memset(visited,0,sizeof(visited));
	memset(can1go,0,sizeof(can1go));
	DFS(1);
	memset(visited,0,sizeof(visited));
	memset(canngo,0,sizeof(canngo));
	rDFS(N);
	cin>>T;
	for(int i=0;i<T;i++){
		cin >> C;
		if(can1go[C] && canngo[C]){
			cout << "Defend the CTP\n";
		}else{
			cout << "Destroyed the CTP\n";
		}
	}
	
	
}