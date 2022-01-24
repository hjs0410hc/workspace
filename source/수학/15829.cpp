#include <bits/stdc++.h>
using namespace std;

int l;
long long int expo{1};
long long int ans{0};
string s;
vector<int> v;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> l;
    cin >> s;
    for(char c:s){
        v.push_back(c-'a'+1);
    }
    for(int i=0;i<l;i++){
        ans += (v[i] * expo)%1234567891;
        expo = (expo * 31) % 1234567891;
    }
    ans %= 1234567891;
    cout << ans;
}