#include <bits/stdc++.h>
using namespace std;

int n,tx;
vector<int> arr;
vector<int> calc;


void solve(){
    arr.clear();
    int ans = 0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> tx;
        arr.push_back(tx);
    }
    calc = arr;
    sort(calc.begin(),calc.end());
    ans = max(ans, arr[n-1]-calc[0]);
    ans = max(ans,calc[n-1]-arr[0]);
    for(int j=0;j<n-1;j++){
        int temp = arr[0];
        for(int i=0;i<n;i++){
            if(i==n-1){
                arr[i] = temp;
            }else{
                arr[i] = arr[i+1];
            }


        }

            /* for(int i=0;i<n;i++){
                cout << arr[i] << " ";
            }
            cout << "\n"; */
        ans = max(ans,arr[n-1]-arr[0]);
    }

    cout << ans << "\n";

}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;while(t--)solve();
    
    
    
    
}