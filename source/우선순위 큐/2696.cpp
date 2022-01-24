#include <bits/stdc++.h>
using namespace std;

int tc,n,x;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>tc;
    while(tc--){
        priority_queue<int,vector<int>> pq; // the first;
        priority_queue<int,vector<int>,greater<int>> pq2; // the last
        int pqsize{0},pq2size{0};
        vector<int> ans;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>x;
            if(i==0){
                pq.push(x);
                pqsize++;
            }else if(pq2.empty()){
                if(x >= pq.top()){
                    pq2.push(x);
                }else{
                    pq2.push(pq.top());
                    pq.pop();
                    pq.push(x);
                }
                pq2size++;
            }else{
                if(x >= pq2.top()){
                    pq2.push(x);
                    pq2size++;
                }else{
                    pq.push(x);
                    pqsize++;
                }
                if((pqsize- pq2size)>= 2){
                    pq2.push(pq.top());
                    pq2size++;
                    pq.pop();
                    pqsize--;
                }else if((pq2size - pqsize) >= 2){
                    pq.push(pq2.top());
                    pqsize++;
                    pq2.pop();
                    pq2size--;
                }
            }
            if(i%2==0){
                ans.push_back(((pq.size() > pq2.size()) ? pq.top(): pq2.top()));
            }
        }
        cout << ans.size() << "\n";
        for(int i=1;i<=ans.size();i++){
            cout << ans[i-1] << " ";
            if(i % 10 == 0) cout << "\n";
        }
        cout << "\n";
    }
    
    
}