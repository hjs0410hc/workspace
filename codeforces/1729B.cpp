#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;cin>>n;
    string s;cin>>s;
    string res = "";
    for(int i=s.length()-1;i>=0;i--){
        if(s[i] == '0'){
            int temp = 0;
            temp += (s[i-2]-'0')*10;
            temp += (s[i-1]-'0');
            res += temp+'a'-1;
            i-=2;
        }else{
            res += s[i]-'0'-1+'a';
        }
    }
    reverse(res.begin(),res.end());
    cout << res << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    int q;cin>>q;while(q--)solve();
}