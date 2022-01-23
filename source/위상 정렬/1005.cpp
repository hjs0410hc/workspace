#include <bits/stdc++.h>
using namespace std;

int T,N,K,W;
vector<int> buildtime;
vector<int> degree;
//vector<bool> checked;
vector<vector<int> > graph;
vector<int> ans;

void toposort(){
	queue<int> q;
	for(int i=1;i<=N;i++){
		if(degree[i] == 0){
			q.push(i);
			ans[i] = buildtime[i];
		}
	}
	while(!q.empty()){
		int f = q.front();
		q.pop();
		if(f == W){
			break;
		}

		for(auto w:graph[f]){
			if((--degree[w]) == 0){
				q.push(w);
			}
			if(ans[w] < ans[f] + buildtime[w]){
				ans[w] = ans[f] + buildtime[w];
			}
		}
	}
}



int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> T;
	while(T--){
		buildtime.clear();
		degree.clear();
		//checked.clear();
		graph.clear();
		ans.clear();


		cin >> N >> K;


		buildtime.resize(N+1);
		degree.resize(N+1);
		//checked.resize(N+1);
		graph.resize(N+1);
		ans.resize(N+1);

		for(int i=1;i<=N;i++){
			cin >> buildtime[i];
		}
		for(int i=0;i<K;i++){
			int s,d;cin>>s>>d;
			graph[s].push_back(d);
			degree[d]++;
		}
		cin >> W;

		toposort();

		cout << ans[W] << "\n";
	}
}