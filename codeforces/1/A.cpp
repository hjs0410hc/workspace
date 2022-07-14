#include <iostream>
using namespace std;

int tc;
int nums = 0;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>tc;
    while(tc--){
        int x;
        for(int i=0;i<4;i++){
            cin >> x;
            if(x!=0){
                nums++;
            }
        }
        if(nums == 0){
            cout << 0;
        }else if(nums == 4){
            cout << 2;
        }else{
            cout << 1;
        }
        cout << '\n';
        nums = 0;
    }
    
    
    
    
}