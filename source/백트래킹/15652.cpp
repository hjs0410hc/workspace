#include <bits/stdc++.h>
using namespace std;

int n,m;
int arr[9];
int temp[9];
bool visited[9];

void DFS(int depth){
    if(depth == m){
        for(int i=0;i<m;i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;   
    }
    for(int i=1;i<=n;i++){
        if(arr[depth-1] <= i){
            visited[i] = true;
            arr[depth] = i;
            DFS(depth+1);
            visited[i] = false;
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m;arr[0]  = -1;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    DFS(0);
}