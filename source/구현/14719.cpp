#include <bits/stdc++.h>
using namespace std;

bool mat[501][501];
int h,w,x;
int ans = 0;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    memset(mat,0,sizeof(mat));
    cin>>h>>w;
    for(int i=0;i<w;i++){ // this is width
        cin>>x;
        for(int j=0;j<x;j++){
            mat[j][i] = true;
        }
    } // 뒤집힘.
    for(int i=0;i<h;i++){
        bool check = false;
        int temp = 0;
        for(int j=0;j<w;j++){
            if(!check){
                if(mat[i][j]){
                    check = true;
                }
            }else{
                if(mat[i][j]){
                    ans += temp;
                    temp = 0;
                }else{
                    temp++;
                }
            }
        }
    }
    cout << ans;

    
}