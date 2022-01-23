#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    string s1,s2;
    cin >> s1>>s2;
    stack<char> st1,st2;
    string& longer = (s1.size() > s2.size()) ? s1 : s2;
    string& shorter = (s1.size() > s2.size()) ? s2: s1;
    int diff = longer.size()-shorter.size();
    if(diff!=0){
        for(int i=0;i<diff;i++){
            shorter = '0' + shorter;
        }
    }
    for(char c:s1){
        st1.push(c);
    }
    for(char c:s2){
        st2.push(c);
    }
    bool prev = false;
    bool carry = false;
    char next = '0';
    string answer = "";
    while(!st1.empty()){
        char c1 = st1.top();
        char c2 = st2.top();
        st1.pop();
        st2.pop();
        if(c1 == '1' && c2 == '1'){
            next = '0';
            carry = true;
        }else if((c1 == '0' && c2 == '1') || (c1=='1' && c2=='0')){
            next = '1';
            carry = false;
        }else if(c1=='0' && c2=='0'){
            next = '0';
            carry = false;
        }
        if(prev){ // prevcarry = 1일때.
            if(next == '1' && !carry){
                next = '0';carry=true;
            }else if(next == '0' && carry){
                next = '1';carry=true;
            }else if(next == '0' && !carry){
                next = '1';
            }
        }
        answer = next + answer;
        prev = carry;
    }
    if(carry){
        answer = '1' + answer;
    }
    while(answer[0] == '0'){
        if(answer.size() == 1){
            break;
        }
        answer.erase(answer.begin());
    }
    cout << answer;
}