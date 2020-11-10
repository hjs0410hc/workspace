#include <bits/stdc++.h>
using namespace std;

int r,c;

char arr[21][21];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> r >> c;
    for(int i=0;i<r;i++){
        string s; cin>>s;
        for(int j=0;j<c;j++){
            arr[i][j]=s[j];
        }
    }
    // 가로탐색
    vector<string> vs;
    for(int i=0;i<r;i++){
        string s = "";
        for(int j=0;j<c;j++){
            if(arr[i][j] == '#'){
                if(s.length() > 1){
                    vs.push_back(s);
                    s= "";
                }else if(s.length() == 1){
                    s= "";
                }
            }else{
                s += arr[i][j];
            }
        }
        if(s.length() > 1){
            vs.push_back(s);
        }
    }
    for(int j=0;j<c;j++){
        string s = "";
        for(int i=0;i<r;i++){
            if(arr[i][j] == '#'){
                if(s.length() > 1){
                    vs.push_back(s);
                    s= "";
                }else if(s.length() == 1){
                    s= "";
                }
            }else{
                s += arr[i][j];
            }
        }
        if(s.length() > 1){
            vs.push_back(s);
        }
    }
    sort(vs.begin(),vs.end());
    cout << vs[0];
}