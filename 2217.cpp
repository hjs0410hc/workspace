#include <bits/stdc++.h>
using namespace std;

int n,t;
priority_queue<int,vector<int>> pq;
priority_queue<int,vector<int>> pq2;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin >> t;
        pq.push(t);
    }
    int count = 0;
    while(!pq.empty()){
        pq2.push( pq.top()*(++count));
        pq.pop();
    }
    cout << pq2.top();
}