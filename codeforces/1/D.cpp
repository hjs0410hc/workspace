#include <bits/stdc++.h>
using namespace std;

int l[500001];
int visited[500001];
int ans[500001];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        memset(l,0,sizeof(l));
        int n,x;cin>>n;
        for(int i=1;i<=n;i++){
            cin>>x;
            if(x==0)x=1;
            l[i] = x;
        }
        for(int i=1;i<=n;i++){
            if(l[i]!=0 && l[i]!=1){
                if(i % l[i] == 0){
                    int temp = i / l[i];
                    ans[i] = temp;
                    visited[temp] = true;
                }
            }else if(l[i] == 0){
                for(int j=1;j<=n;j++){
                    if(!visited[j] && j > i){
                        visited[j] = true;
                        ans[i]=j;
                    }
                }
            }else if(1){
                
            }
        }
    }   
    
    
    
    
}