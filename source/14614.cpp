#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;

ull A,B;
string C;
bool isOdd; // C가 홀수인가???

// C가 짝수면 아무것도 안해도 된다. 어차피 돌아오게 되어있다.


int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> A >> B >> C;
	isOdd = (((C.back()-'0') % 2 == 0)? false : true);
	if(isOdd){
		cout << (A xor B);
	}else{
		cout << A;
	}
}