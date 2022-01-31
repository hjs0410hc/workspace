#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
    long long val=0;
    for(int i=0;i<3;i++){
        cin >> s;
        int temp;
        if(s=="black"){
            temp = 0;
        }else if(s=="brown"){
            temp = 1;
        }else if(s=="red"){
            temp = 2;
        }else if(s=="orange"){
            temp = 3;
        }else if(s=="yellow"){
            temp = 4;
        }else if(s=="green"){
            temp = 5;
        }else if(s=="blue"){
            temp = 6;
        }else if(s=="violet"){
            temp = 7;
        }else if(s=="grey"){
            temp = 8;
        }else if(s=="white"){
            temp = 9;
        }
        if(i<2){
            val*=10;
            val+=temp;
        }else{
            val*=pow(10,temp);
        }
    }
    cout << val;
}