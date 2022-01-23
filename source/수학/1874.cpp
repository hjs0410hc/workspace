#include <bits/stdc++.h>
using namespace std;

int n,k,cur{0};
stack<int> st;
vector<char> ans;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin >> k;
/*         if(st.empty()){ // 첫 동작
            for(int i=0;i<k;i++){
                st.push(++cur);
                ans.push_back('+');
            }
            st.pop();
            ans.push_back('-');
        } */
        //cur ==4
        if(k < cur){
            if(st.top() == k){
                st.pop();
                ans.push_back('-');
            }else{
                cout << "NO";return 0;
            }
        }
        if(k > cur){ // k =6 cur = 4
            for(int i=cur;i<k;i++){
                st.push(++cur);
                ans.push_back('+');
            }
            st.pop();
            ans.push_back('-');
        }
    }
    for(char c:ans){
        cout << c << "\n";
    }
}