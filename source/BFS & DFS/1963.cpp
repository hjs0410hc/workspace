#include <bits/stdc++.h>
using namespace std;

int mat[10000];
int tc,x,y;
int ans = 2e9;
bool visited[10000];

int jari(int x,int y){
    return (x/((int)pow(10,y)))%10;
}

void bfs(){
    queue<pair<int,int>> q;
    q.push({x,0});
    while(!q.empty()){
        pair<int,int> p = q.front();
        q.pop();
        if(p.first == y){
            ans = min(ans,p.second);
        }
        for(int j=0;j<4;j++){
            for(int i=0;i<=9;i++){
                int tr = p.first - jari(p.first,j)*pow(10,j)+i*pow(10,j);
                // 1의자리 바꾸기 1033 - 3 + 0
                if(tr >= 1000 && mat[tr] != -1 && !visited[tr]){
                    visited[tr] = true;
                    q.push({tr,p.second+1});
                }
            }
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);    memset(mat,0,sizeof(mat));
    mat[0] = -1;
    mat[1] = -1;
    for(int i=2;i<10000;i++){
        if(mat[i] == -1){
            continue;
        }else{
            // mat[i] != -1인 경우 그것은 소수당
            for(int j=2;i*j<10000;j++){
                mat[i*j] = -1;
            }
        }
    }
    cin>>tc;
    while(tc--){
        memset(visited,0,sizeof(visited));
        ans = 2e9;
        cin >>x>>y;
        if(x==y){
            cout << 0 << "\n";continue;
        }else{
            bfs();
        }
        cout << ans << "\n";
    }
    
    
}