#include <bits/stdc++.h>
using namespace std;

int n,tot{0};
priority_queue<int,vector<int>,greater<int> > pq;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n;
    int p;
    for(int i=0;i<n;i++){
        cin >> p;
        pq.push(p);
    }
    while(pq.size() > 1){
        int n1,n2;
        n1 = pq.top();
        pq.pop();
        n2 = pq.top();
        pq.pop();
        pq.push(n1+n2);
        tot += n1+n2;
    }
    cout << tot;
}