#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int x,y,z;
    cin>>x>>y>>z;
    cout<<(x+y)%z<<"\n"<<((x%z)+(y%z))%z<<"\n"<<(x*y)%z<<"\n"<<((x%z)*(y%z))%z;   
    
    
}