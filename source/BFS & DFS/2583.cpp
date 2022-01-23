#include <bits/stdc++.h>
using namespace std;

int m,n,k;
int mapm[101][101];
bool visited[101][101];
int howmany = 0;
int range = 0;
vector<int> v;
//x가 COL, y가 ROW
void setMap(pair<int,int> p1,pair<int,int> p2){
	for(int i=p1.second;i<p2.second;i++){
		for(int j=p1.first;j<p2.first;j++){
			mapm[i][j] = 1;
		}
	}
}

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

void DFS(int x,int y){
	visited[x][y] = true;
	range++;
	for(int i=0;i<4;i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(nx >= 0 && ny >= 0 && nx < m && ny < n && mapm[nx][ny] == 0 &&!visited[nx][ny]){
			DFS(nx,ny);
		}
	}
	
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	memset(mapm,0,sizeof(mapm));
	cin>>m>>n>>k;
	for(int i=0;i<k;i++){
		int p11,p12,p21,p22;cin>>p11>>p12>>p21>>p22;
		setMap({p11,p12},{p21,p22});
	}

	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(mapm[i][j]==0 && !visited[i][j]){
				howmany++;
				range=0;
				DFS(i,j);
				v.push_back(range);
			}
		}
	}
	cout << howmany << "\n";
	sort(v.begin(),v.end());
	for(auto w:v){
		cout << w << " ";
	}
}