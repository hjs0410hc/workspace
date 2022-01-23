#include <bits/stdc++.h>
using namespace std;

int tc;

int main(){
    //ios_base::sync_with_stdio(false);cin.tie(0);

    cin>>tc;
    while(tc--){
        int h,w,n;cin>>h>>w>>n;
        int a{0},b{1};
        for(int i=0;i<n;i++){
            a++;
            if(a>h){
                a=1;b++;
            }
        }
        cout << a << setfill('0') << setw(2) << b << "\n";
    }
    
    
}