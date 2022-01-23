#include <bits/stdc++.h>
using namespace std;

string s;
vector<string> vs;
int n;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> s;
    n = s.length();
    vs.push_back(s);
    for(int i=0;i<n-1;i++){
        s.erase(s.begin());
        vs.push_back(s);
    }
    sort(vs.begin(),vs.end());
    for(auto c:vs){
        cout << c << "\n";
    }
}