#include <bits/stdc++.h>
using namespace std;

string num;
int k;
int arr[3];
string res;
int ans;

void solve(){
    if(res.length() > 0 && stoi(num) >= stoi(res)){
        ans=max(ans,stoi(res));
    }
    if(res.length() == num.length()){
        return;
    }
    for(int i=0;i<k;i++){
        res += arr[i]+'0';
        solve();
        res.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> num;
    cin >> k;
    for(int i=0;i<k;i++){
        cin >> arr[i];
    }
    solve();
    cout << ans;
}