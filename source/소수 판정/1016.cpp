#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int mat[1000101];

int helper[1000001];
vector<int> v; //소수 2부터 백만백까지의 소수가 들가잇다
vector<ll> jgv; // 소수의 제곱수

ll Min,Max;


int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    memset(mat,0,sizeof(mat));
    memset(helper,0,sizeof(helper));
    mat[0] = -1;
    mat[1] = -1;
    for(int i=2;i<1000101;i++){
        if(mat[i] == -1){
            continue;
        }else{
            // mat[i] != -1인 경우, 즉 0인 경우. 그것은 소수당
            for(int j=2;i*j<1000101;j++){
                mat[i*j] = -1;
            }
        }
    }
    for(int i=0;i<1000101;i++){
        if(mat[i] != -1){
            v.push_back(i);
        }
    }
    for(int i=0;i<v.size();i++){
        jgv.push_back(pow(v[i],2));
    }
    //제반작업끝

    cin >> Min >> Max;

    for(int i=0;i<jgv.size();i++){ // 변형된 에라스토테네스의 체
        for(ll j=(Min%jgv[i])?Min/jgv[i]+1:Min/jgv[i];jgv[i]*j<=Max;j++){ // jgv[i]가 제곱수. j가 계수.
            // jgv[i]*j는 전부 제곱ㄴㄴ수가 아니다. 그리고 무조건 Min보다 같거나 크다.
            //cout << jgv[i]*j << " is dead man\n";
            helper[jgv[i]*j-Min] = -1;
        }
    }
    ll ans = 0;
    for(ll j=Min;j<=Max;j++){
        if(helper[j-Min] != -1){
            ans++;
        }
    }
    cout << ans;
}