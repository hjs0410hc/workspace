#include <bits/stdc++.h>
using namespace std;

int x,y;
int sum = 0;

int main(){
    cin>>x>>y;
    int count = 0;
    while(y>0){
        cout << x*(y%10) << "\n";
        sum += x*(y%10)*pow(10,count++);
        y /= 10;
    }
    cout << sum;
}