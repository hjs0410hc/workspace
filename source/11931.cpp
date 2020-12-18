#include <bits/stdc++.h>
using namespace std;
// O(log_2 n) time complexity descending sort
priority_queue<int,vector<int>> pq;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    
    while(n--){
        int k;cin>>k;
        pq.push(k);
    }

    while(!pq.empty()){
        cout << pq.top() << "\n";
        pq.pop();
    }
}