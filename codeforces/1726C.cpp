#include <bits/stdc++.h>
using namespace std;

bool depthvisit[200001];


void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int depth = 0;
    int ans = 0;
    stack<int> st;
    for(int i=0;i<s.length();i++){
        if(s[i] == '('){
            depth++;
            st.push(i);
            
            depthvisit[depth] = true;
        }else{
            depth--;
            st.pop();
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t; while (t--)solve();




}