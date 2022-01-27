#include <bits/stdc++.h>
using namespace std;

int n,m,x;
vector<int> arr;
int ans[9];

void dfs(int depth){
    if(depth == m){
        for(int i=0;i<m;i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i=0;i<n;i++){
        //중복이 가능하니까 visited는 없다.
        if(depth == 0){
            ans[depth] = arr[i];
            dfs(depth+1);
        }else{
            if(ans[depth-1] <= arr[i]){ // 전단계보단 크면.. 넣어야지....
                ans[depth] = arr[i];
                dfs(depth+1);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>x;
        arr.push_back(x);
    }
    sort(arr.begin(),arr.end());
    dfs(0);
    
}