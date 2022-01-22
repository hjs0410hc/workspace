#include <bits/stdc++.h>
using namespace std;

int arr[1000001];
vector<int> LIS; // LIS = smallest last word of LIS (length = len)
int n;


int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        if(i==0){
            LIS.push_back(arr[i]);
        }else if(LIS[LIS.size()-1] < arr[i]){
            LIS.push_back(arr[i]);
        }else{
            *lower_bound(LIS.begin(),LIS.end(),arr[i]) = arr[i];
        }
    }  
    cout << LIS.size();
    
}