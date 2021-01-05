#include <bits/stdc++.h>
#define INF 2e9;
using namespace std;

int V,E,s;
vector<pair<int,int> > graph[20001];
int dist[20001];
int prevlist[20001];

class Comparator{ // custom comparator for PQ(making minheap). however it causes TL.
	public:
	bool operator()(pair<int,int> p1, pair<int,int> p2){
		return p1.first < p2.first;
	}
};

priority_queue<pair<int,int>> pq;
// pair.first = dist , pair.second = INDEX

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>V>>E;
	cin >> s;
	for(int i=0;i<E;i++){
		int s,d,w;cin>>s>>d>>w;
		graph[s].push_back({d,w});
	}
	for(int i=1;i<=V;i++){
		dist[i] = INF;
	}
	dist[s] = 0;
	pq.push({0,s});

	while(!pq.empty()){
		int cost = -pq.top().first; // this is ........ for making minPQ
		int here = pq.top().second;
		pq.pop();

		for(int i=0;i<graph[here].size();i++){
			int next = graph[here][i].first;
			int nextcost = graph[here][i].second;

			if(dist[next] > dist[here]+nextcost){
				dist[next] = dist[here]+nextcost;
				pq.push({-dist[next],next}); // this too.
			}
		}
	}
	
	for(int i=1;i<=V;i++){
		if(dist[i] == 2e9){
			cout << "INF\n";
		}else{
			cout << dist[i]<<'\n';
		}
	}
}