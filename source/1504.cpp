#include <bits/stdc++.h>
using namespace std;

int N,E;
int v1,v2;
vector<pair<int,int>> graph[801]; // DEST / WEIGHT
int dist[801];
bool checked[801];


void Dijkstra(int s, int d){
	priority_queue<pair<int,int> > pq;
	for(int i=0;i<801;i++){
		checked[i]=false;
		dist[i]=2e8;
	}
	dist[s] = 0;
	pq.push({0,s});
	while(!pq.empty()){
		int curw = -pq.top().first;
		int curpos = pq.top().second;
		//checked[curpos] = true;
		pq.pop();
		for(pair<int,int> p : graph[curpos]){
			if(dist[p.first] > curw +p.second){
				dist[p.first] = curw + p.second;
				pq.push({-dist[p.first],p.first});
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> N >> E;
	for(int i=0;i<E;i++){
		int s,d,w;cin>>s>>d>>w;
		graph[s].push_back({d,w});
		graph[d].push_back({s,w});
	}
	cin >> v1 >> v2;
	int ans1 = 0;
	Dijkstra(1,v1);
	ans1 += dist[v1];
	Dijkstra(v1,v2);
	ans1 += dist[v2];
	Dijkstra(v2,N);
	ans1 += dist[N];
	
	int ans2 = 0;
	Dijkstra(1,v2);
	ans2 += dist[v2];
	Dijkstra(v2,v1);
	ans2 += dist[v1];
	Dijkstra(v1,N);
	ans2 += dist[N];
	
	if(ans1 >= 2e8 && ans2 >= 2e8){
		cout << -1;return 0;
	}else if(ans1 >= ans2){
		cout << ans2; return 0;
	}else{
		cout << ans1; return 0;
	}

}