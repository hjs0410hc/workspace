#include <bits/stdc++.h>
using namespace std;

int x_1,x_2,x_3,y_1,y_2,y_3;



int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> x_1 >> y_1 >> x_2 >> y_2 >> x_3 >> y_3;

    int calc = (x_2-x_1)*(y_3-y_2)-(x_3-x_2)*(y_2-y_1);
    if(calc==0){
        cout << 0;
    }else if(calc >0){
        cout << 1;
    }else{
        cout << -1;
    }
    
    
}