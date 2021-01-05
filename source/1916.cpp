#include <bits/stdc++.h>
#define INF 2e9;
using namespace std;

int V,E,s;
vector<pair<int,int> > graph[20001];
int dist[20001];
int prevlist[20001];

priority_queue<pair<int,int>> pq;
// pair.first = dist , pair.second = INDEX

void Dijkstra(int start,int goal){
	for(int i=1;i<=V;i++){
		dist[i] = INF;
	}
	dist[start] = 0;
	pq.push({0,start});

	while(!pq.empty()){
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if(here==goal){
			break;
		}

		for(int i=0;i<graph[here].size();i++){
			int next = graph[here][i].first;
			int nextcost = graph[here][i].second;

			if(dist[next] > dist[here]+nextcost){
				dist[next] = dist[here]+nextcost;
				pq.push({-dist[next],next});
			}
		}
	}

}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>V>>E;
	for(int i=0;i<E;i++){
		int src,dst,len;cin>>src>>dst>>len;
		graph[src].push_back({dst,len});
	}
	int start,goal;cin>>start>>goal;
	Dijkstra(start,goal);
	cout << dist[goal];
}