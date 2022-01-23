#include <bits/stdc++.h>
using namespace std;

string s1,s2;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>s1>>s2;
    string& longer = (s1.size()>s2.size())?s1:s2;
    string& shorter = (longer == s1) ? s2 : s1;
    int diff = longer.size()- shorter.size();
    int k = diff;
    while(k--){
        shorter = '0' + shorter;
    }
    stack<int> st1,st2;
    for(char c:longer){
        st1.push(c-'0');
    }
    for(char c:shorter){
        st2.push(c-'0');
    }
    string answer = "";
    int carry = 0;
    int prevcarry = 0;
    while(!st1.empty()){
        int t1= st1.top();
        int t2=st2.top();
        st1.pop();st2.pop();
        int target = 0;
        if(t1+t2+prevcarry>=10){
            carry = 1;
            target = t1+t2+prevcarry-10;
        }else{
            carry = 0;
            target =t1+t2+prevcarry;
        }
        answer = (char)(target+'0')+answer;
        prevcarry = carry;
    }
    if(prevcarry){
        answer = '1'+answer;
    }
    cout << answer;
    
}