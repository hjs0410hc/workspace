#include <bits/stdc++.h>
using namespace std;

int n;

int RCL[15];
long long int ans = 0;
void DFS(int depth){
    if(depth==n){
        ans++;
        return;
    }
    for(int i=0;i<n;i++){ // i = row?
        bool can = true;
        for(int j=0;j<depth;j++){ // j = 지금까지 해왔던 row. (i)
            if(RCL[j] == i || abs(depth-j) == abs(i-RCL[j])){
                can = false;
                break;
            }
        }
        if(can){
            RCL[depth] = i;
            DFS(depth+1);
        }
    }
}

int main(){
    //ios_base::sync_with_stdio(false);cin.tie(0);
    memset(RCL,0,sizeof(RCL));
    cin>>n;
    DFS(0);
    cout << ans;
}