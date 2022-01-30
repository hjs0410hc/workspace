#include <bits/stdc++.h>
using namespace std;

int n,k,x;
vector<int> v; //5백만개의int,20MB.
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());//O(nlogn)<-5M*log(5M)=
    cout<<v[k];
}


/* #include <bits/stdc++.h>
using namespace std;

priority_queue<int,vector<int>,less<int>> pq;
int n,k,x;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >>n>>k;
    for(int i=0;i<n;i++){
        cin>>x;
        pq.push(x);
        while(pq.size()>k){ // pq사이즈를 k개로 통제.
            pq.pop();
        }
    }
    cout <<pq.top();
    
} */