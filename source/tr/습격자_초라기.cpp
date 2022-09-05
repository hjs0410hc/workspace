#include <bits/stdc++.h>
using namespace std;



int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        int n,w;cin>>n>>w;
        int mat[2][n+1]{0,};
        vector<pair<int,int>> dp[2][n+1];
        pair<int,int> dp2[2][n+1];
        for(int i=0;i<2;i++){
            for(int j=1;j<=n;j++){
                cin>>mat[i][j];
            }
        }
        for(int i=0;i<2;i++){
            for(int j=1;j<=n;j++){
                //현재수는 mat[i][j]
                //왼쪽 mat[i][j-1]
                if(mat[i][j]+mat[i][(j-1 <= 0) ? n :j-1] <= w){
                    dp[i][j].push_back({i,(j-1 <= 0) ? n :j-1});
                }
                //오른쪽 mat[i][j+1];
                if(mat[i][j]+mat[i][(j+1 > n) ? 1 :j+1] <= w){
                    dp[i][j].push_back({i,(j+1 > n) ? 1 :j+1});
                }
                //행변경+1 mat[i+1][j];
                if(i != 1 && mat[i][j]+mat[i+1][j] <= w){
                    dp[i][j].push_back({i+1,j});
                }
                //행변경-1 mat[i-1][j];
                if(i != 0 && mat[i][j]+mat[i-1][j] <= w){
                    dp[i][j].push_back({i-1,j});
                }
            }
        }
        for(int i=0;i<2;i++){ // dp 순회
            for(int j=1;j<=n;j++){
                
            }
        }

    }   
    
    
    
    
}