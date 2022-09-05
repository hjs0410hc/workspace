#include <bits/stdc++.h>
using namespace std;

int n,k;
int arr[11];
map<string,bool> mp;

string res = "";

int num = 0;
bool visited[11];

vector<int> v;

void solve(){
    if(num == k){
        //cout << num << " " << k << " " << res<< "\n";
        mp[res] = true;
        return;
    }
    for(int i=0;i<n;i++){
        if(visited[i]){
            //cout << "현재 res : " << res << "넘어감 :" << i << "\n" ;
            continue;
        }
        if(arr[i] < 10){
            res += arr[i]+'0';
        }else{
            res += (arr[i]/10)+'0';
            res += (arr[i]%10)+'0';
        }
            num++;
            visited[i] = true;
            solve();
            num--;
            visited[i] = false;
            if(arr[i] < 10){
            res.pop_back();

            }else{
                res.pop_back();
                res.pop_back();
            }
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    memset(visited,0,sizeof(visited));
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    solve();
    cout << mp.size();
    
    
}