#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    while(true){
        int n;cin>>n;
        if(n==0){
            break;
        }
        int org=n;int rev=0;
        while(n != 0){
            rev*=10;
            rev+=n%10;
            n/=10;
        }
        if(org==rev){
            cout << "yes";
        }else{
            cout << "no";
        }cout << "\n";

    }



}