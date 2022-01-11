#include <bits/stdc++.h>
using namespace std;

int a,b,v;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> a >> b >> v;
    if(a==v){
        cout << 1;return 0;
    }
    int onedaydist = a-b;
    int finaldist = v-a;
    int daystoapproachfinal = (finaldist%onedaydist)?finaldist/onedaydist + 1:finaldist/onedaydist;
    int answer = daystoapproachfinal + 1;
    cout << answer;
    
    
}