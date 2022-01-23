#include <bits/stdc++.h>
using namespace std;

int jangma = 0;
int mat[101][101];
bool visited[101][101];
int n;
pair<int,int> dxdy[4] = {{1,0},{-1,0},{0,1},{0,-1}};
int maxi = 0;
vector<int> ans;


void BFS(int r,int c){
    queue<pair<int,int>> q;
    q.push({r,c});
    while(!q.empty()){
        int tr = q.front().first;
        int tc = q.front().second;
        q.pop();
        if(mat[tr][tc] > jangma && !visited[tr][tc]){
            visited[tr][tc] = true;
            for(int i=0;i<4;i++){
                int ntr = tr+dxdy[i].first;
                int ntc = tc+dxdy[i].second;
                if(ntr < n&& ntr >= 0&& ntc <n&& ntc >=0&& mat[ntr][ntc] > jangma && !visited[ntr][ntc]){
                    q.push({ntr,ntc});
                }else if(ntr < n&& ntr >= 0&& ntc <n&& ntc >=0&&mat[ntr][ntc] <= jangma && !visited[ntr][ntc]){
                    visited[ntr][ntc]= true;
                }
            }
        }
    }
}
//최대한 queue에 들어가는 게 적어야한다!

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    int k;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> k;mat[i][j]=k;maxi=(k>maxi)?k:maxi;
        }
    }
    for(jangma;jangma<=maxi;jangma++){  
        memset(visited,0,sizeof(visited));
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] > jangma && !visited[i][j]){
                    BFS(i,j); // this will impact on other safe blocks. 최대한 BFS함수를 적게 호출해야한다!.
                    count++;
                }else if(!visited[i][j]){
                    visited[i][j] = true; // NO COUNT FOR DROWNED
                }
            }
        }
        ans.push_back(count);
    }
    sort(ans.begin(),ans.end(),greater<int>());
    cout << ans[0];
}