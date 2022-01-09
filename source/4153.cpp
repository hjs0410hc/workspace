#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    while(true){
        int x,y,z;cin>>x>>y>>z;
        if(x==0 && y==0 && z==0){
            break;
        }
        vector<int> v{x,y,z};
        sort(v.begin(),v.end());
        if(pow(v[0],2)+pow(v[1],2)==pow(v[2],2)){
            cout <<"right";
        }else{
            cout <<"wrong";
        }cout << "\n";
    }

}