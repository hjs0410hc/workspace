#include <bits/stdc++.h>
using namespace std;

int t,n;
int visited[200001];


int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        if(n==1){
            cout << 1 << '\n' << 1 << '\n';
            continue;
        }
        int d = 2;
        vector<int> v;
        for(int i=1;i<=n;i++){
            if(!visited[i]){
                v.push_back(i);
                visited[i] = true;
                for(int j=i*2;j<=n;j*=2){
                    if(!visited[j]){
                        visited[j] = true;
                        v.push_back(j);
                    }
                }
            }
        }
        memset(visited,0,sizeof(visited));
        cout << 2 << '\n';
        for(int i:v){
            cout << i << ' ';
        }
        cout << '\n';
    }
    
    
    
    
}