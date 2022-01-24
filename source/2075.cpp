#include <bits/stdc++.h>
using namespace std;

priority_queue<int,vector<int>,greater<int>> pq;

int n,k;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> k;
            pq.push(k);
            while(pq.size() > n){ // god damn fixation !!!!
                pq.pop();
            }
        }
    }
    cout << pq.top();
    
}