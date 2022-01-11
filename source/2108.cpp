#include <bits/stdc++.h>
using namespace std;

int n,k,sum{0};
vector<int> v;
vector<pair<int,int>> vp;


bool comparator(pair<int,int>& p1,pair<int,int>& p2){
    if(p1.second == p2.second){
        return p1.first < p2.first;
    }else{
        return p1.second > p2.second;
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    for(int i=-4000;i<4001;i++){
        vp.push_back({i,0});
    }
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> k;
        v.push_back(k);
        vp[k+4000].second++;
        sum += k;
    }
    sort(v.begin(),v.end());
    sort(vp.begin(),vp.end(),comparator);
    int avg = (int)(round(((float)sum)/n)); // 1 산술평균
    int ctr = v[n/2];               // 2 중앙값
    int freq = (vp[0].second != vp[1].second)?vp[0].first :vp[1].first;      //최빈값
    int range = *(v.end()-1) - v[0]; // 4 범위
    cout << avg << "\n" << ctr << "\n" << freq << "\n" << range;
}