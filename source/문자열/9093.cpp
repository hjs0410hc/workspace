#include <bits/stdc++.h>
using namespace std;

stack<char> st;
int t;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> t;
    cin.ignore();
    while(t--){
        string s;
        getline(cin,s);
        for(int i=0;i<s.length();i++){
            if(s[i] == ' '){
                while(!st.empty()){
                    cout << st.top();
                    st.pop();
                }
                cout << ' ';
            }else{
                st.push(s[i]);
            }
        }
        while(!st.empty()){
            cout<<st.top();
            st.pop();
        }
        cout << '\n';
    }
    
    
    
    
}