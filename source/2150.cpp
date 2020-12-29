#include <bits/stdc++.h>
using namespace std;

vector<int> vertexlist;
vector<int> graph[10001];
vector<int> rgraph[10001];
vector<vector<int>> v;
int finishtime[10001];
bool visited[10001];
int ktime = 0;

void DFS(int x){
	visited[x]=true;
	for(int w:graph[x]){
		if(!visited[w]){
			DFS(w);
		}
	}
	finishtime[x] = ++ktime;
}

void rDFS(int x, vector<int>& v){
	visited[x] = true;
	v.push_back(x);
	for(int w:rgraph[x]){
		if(!visited[w]){
			rDFS(w,v);
		}
	}
}

bool comparator(int i1,int i2){
	return finishtime[i1] > finishtime[i2];
}

bool vectorcomparator(vector<int>& v1,vector<int>& v2){
	return *(v1.begin()) < *(v2.begin());
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int V,E;cin>>V>>E;
	for(int i=1;i<=V;i++){
		vertexlist.push_back(i);
	}
	for(int i=0;i<E;i++){
		int s,d;cin>>s>>d;
		graph[s].push_back(d);
		rgraph[d].push_back(s);
		
	}
	for(int i=0;i<vertexlist.size();i++){
		if(!visited[vertexlist[i]]){
			DFS(vertexlist[i]);
		}
	}
	memset(visited,0,sizeof(visited));
	sort(vertexlist.begin(),vertexlist.end(),comparator);
	for(int i=0;i<vertexlist.size();i++){
		if(!visited[vertexlist[i]]){
			vector<int> tempv;
			rDFS(vertexlist[i],tempv);
			sort(tempv.begin(),tempv.end());
			tempv.push_back(-1);
			v.push_back(tempv);
		}
	}
	cout << v.size() << "\n";
	sort(v.begin(),v.end(),vectorcomparator);
	for(auto V:v){
		for(auto w:V){
			cout << w << " ";
		}
		cout << "\n";
	}
}