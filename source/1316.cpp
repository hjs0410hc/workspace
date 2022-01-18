#include <bits/stdc++.h>
using namespace std;

int n;
string t;
bool visited[27];
int ans=0;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin >> t;
        char prev;
        bool fail=false;
        memset(visited,0,sizeof(visited));
        for(int j=0;j<t.size();j++){
            if(j==0){
                prev=t[j];
                visited[t[j]-'a'] = true;;
            }else if(prev != t[j] && visited[t[j]-'a']){
                fail=true;
                break;
            }else{
                prev=t[j];
                visited[t[j]-'a'] = true;
            }
        }
        if(!fail){
            ans++;
        }
    }
    cout << ans;
    
}