#include <bits/stdc++.h>
using namespace std;

priority_queue<int,vector<int>,greater<int>> pq;
pair<int,int> p[3];
int x,y,t,r;
double ans=0;

void func(int i1,int i2,int i3){
    pq.push(sqrt((x-p[i1].first)*(x-p[i1].first)+(y-p[i1].second)*(y-p[i1].second))
        +sqrt((p[i1].first-p[i2].first)*(p[i1].first-p[i2].first)+(p[i1].second-p[i2].second)*(p[i1].second-p[i2].second))
        +sqrt((p[i2].first-p[i3].first)*(p[i2].first-p[i3].first)+(p[i2].second-p[i3].second)*(p[i2].second-p[i3].second)));
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >>x>>y;
    for(int i=0;i<3;i++){
        cin >> t >> r;
        p[i].first =t;
        p[i].second = r;
    }


    //1,2,3
        func(0,1,2);
    //1,3,2
        func(0,2,1);

    //2,1,3
        func(1,0,2);

    //2,3,1
        func(1,2,0);

    //3,1,2
        func(2,0,1);

    //3,2,1
        func(2,1,0);

        cout << pq.top();
}