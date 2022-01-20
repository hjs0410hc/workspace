#include <bits/stdc++.h>
using namespace std;

priority_queue<int,vector<int>> pq;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;int k;
    for(int i=0;i<n;i++){
        cin>>k;
        if(k==0){
            if(pq.empty()){
                cout << -1 << "\n";
            }else{
                cout << pq.top() << "\n";
                pq.pop();
            }
        }else{
            int p;
            for(int i=0;i<k;i++){
                cin >> p;
                pq.push(p);
            }
        }
    }
    
    
}