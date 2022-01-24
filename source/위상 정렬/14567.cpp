#include <bits/stdc++.h>
using namespace std;



int N,M,cur;
vector<int> graph[1001];
int degree[1001];
bool checked[1001];
vector<pair<int,int>> ans;

bool comparator(const pair<int,int>& i1,const pair<int,int>& i2){
	return i1.second < i2.second;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	memset(degree,0,sizeof(degree));
	memset(checked,0,sizeof(checked));
	cin >> N>>M;
	for(int i=0;i<M;i++){
		int s,d;cin>>s>>d;
		graph[s].push_back(d);
		degree[d]++;
	}
	cur = 0;
	int x = 1;
	queue<int> q;
	while(cur < N){
		for(int i=1;i<=N;i++){
			if(degree[i] == 0 && !checked[i]){
				checked[i] = true;
				q.push(i);
				cur++;
			}
		}
		while(!q.empty()){
			for(auto w:graph[q.front()]){
				degree[w]--;
			}
			ans.push_back({x,q.front()});
			q.pop();
		}
		x++;
	}

	sort(ans.begin(),ans.end(),comparator);

	for(auto p:ans){
		cout << p.first << " ";
	}
}