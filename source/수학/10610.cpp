#include <bits/stdc++.h>
using namespace std;
// 문제조건안보고 stoi 썼다가 10만자리수의 영압에 당했다
// 30의 배수는 3의 배수이며 10의 배수이기도 하므로
// 10의 배수 판단: 마지막 숫자가 0
// 3의 배수 판단: 모든 자리 더해서 mod 3=0
// 근데 어떻게 정렬만 해서 되는 건지 모르겠다.

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	string n;cin>>n;
	sort(n.begin(),n.end(),greater<char>());
	int sum = 0;
	for(int i=0;i<n.length();i++){
		sum+= (n[i]-'0');
	}
	if(sum % 3 == 0 && *(n.end()-1) == '0'){
		cout << n;
	}else{
		cout << -1;
	}
}