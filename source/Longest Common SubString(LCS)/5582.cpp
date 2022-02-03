#include <bits/stdc++.h>
using namespace std;

string s1,s2;
int LCS[4001][4001]; // 64MB row for s2, col for s1.
int ans = 0 ;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>> s1>>s2;
    LCS[0][0] = 0;
    for(int i=1;i<=s1.size();i++){
        LCS[0][i] = 0;
    }
    for(int i=1;i<=s2.size();i++){
        LCS[i][0] = 0;
    }
    for(int i=1;i<=s1.size();i++){
        for(int j=1;j<=s2.size();j++){
            if(s1[i-1]==s2[j-1]){
            LCS[i][j] = LCS[i-1][j-1]+1;
            ans = max(LCS[i][j],ans);
        }
            else{
            LCS[i][j] = 0;}
        }
    }
    cout << ans;
}