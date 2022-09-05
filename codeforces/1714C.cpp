#include <bits/stdc++.h>
using namespace std;

void solve(){
    int x;cin>>x;
    if(x>=1 && x<= 9){
        cout << x << "\n";
    }else if(x>=10&&x<=17){
        cout << x-9 << 9 << "\n";
    }else if(x>=18&&x<=24){
        cout <<x-8-9<< 8 <<9 << "\n";
    }else if(x>=25&&x<=30){
        cout <<x-7-8-9<<7<< 8 <<9 << "\n";
    }else if(x>=31&&x<=35){
        cout <<x-6-7-8-9<<6<<7<< 8 <<9 << "\n";
    }else if(x>=36&&x<=39){
        cout <<x-5-6-7-8-9<<5<<6<<7<< 8 <<9 << "\n";
    }else if(x>=40&&x<=42){
        cout <<x-4-5-6-7-8-9<<4<<5<<6<<7<< 8 <<9 << "\n";
    }else if(x>=43&&x<=44){
        cout <<x-3-4-5-6-7-8-9<<3<<4<<5<<6<<7<< 8 <<9 << "\n";
    }else if(x==45){
        cout << "123456789\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;while(t--){solve();}
    
    
    
    
}