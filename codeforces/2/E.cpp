#include <bits/stdc++.h>
using namespace std;

int mat[101][101];
bool visited[101][101];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        memset(mat,0,sizeof(mat));
        memset(visited,0,sizeof(visited));
        int ans = 0;
        int n,x;cin>>n;
        for(int i=0;i<n;i++){
            string s;cin>>s;
            int jdx=0;
            for(auto c:s){
                mat[i][jdx++]=(c-'0');
            }
        }
        //90도회전 x4
        /* for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                res90[j][n-1-i] = mat[i][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(res90[i][j] != mat[i][j]){
                    res90[i][j] = (res90[i][j]==0)? 1:0;
                    ans++;
                }
            }
        } */

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j])continue;
                visited[i][j] = true;
                int ti = i;
                int tj = j;
                int diff = 0;
                for(int k=0;k<3;k++){
                    int temp = ti;
                    ti = tj;
                    tj = n-1-temp;
                    visited[ti][tj] = true;
                    if(mat[ti][tj] != mat[i][j]){
                        diff++;
                    }
                }
                if(diff > 2){ // 3개를 다 바꾸라고? 하나만 바꾸면 된다.
                    ans++;
                }else{ // 2개 이하로 바꾸는 경우
                    ans += diff;
                }
            }
        }
        
        cout << ans << "\n";
    }
    
    
    
    
}