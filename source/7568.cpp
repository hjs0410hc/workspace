#include <bits/stdc++.h>
using namespace std;

int n,x,y;

vector<pair<int,int>> vp;
vector<int> ans;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x >> y;
        vp.push_back({x,y}); // NO SORTING!!!
        ans.push_back(1); // EVERY MEN HAS DREAM THAT HE COULD BE THE 1ST...
    }
    for(int i=0;i<vp.size();i++){
        for(int j=0;j<vp.size();j++){
            if(vp[j].first > vp[i].first && vp[j].second > vp[i].second){
                ans[i]++;
            }
        }
    }
    for(int i:ans){
        cout << i << " ";
    }
}