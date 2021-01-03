#include <bits/stdc++.h>
using namespace std;
int t,m;
string n;
typedef unsigned long long int ull;

void display(const int& i){
	cout << i << ".";
}


int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin >> m;
		if(m==1){ // IPv8 to Unsigned 64bit Integer
			string n;cin>>n;
			ull ans = 0;
			int temp = 0;
			vector<int> v;
			for(int i=0;i<=n.length();i++){
				if(i==n.length()){
					v.push_back(temp);
					break;
				}
				char c = n[i];
				if(c=='.'){
					v.push_back(temp);
					temp = 0;
				}else{
					temp*=10;
					temp+=(c-'0');
				}
			}
			string s = "";
			string stemp = "";
			for(int w:v){
				int count = 0;
				while(count < 8){
					stemp += ((w%2==0)?"0":"1");
					w /= 2;
					count++;
				}
				reverse(stemp.begin(),stemp.end());
				s+=stemp;
				stemp = "";
			}
			for(char c:s){
				ans *= 2;
				if(c=='1'){
					ans+=1;
				}
			}
			cout << ans << "\n";
		}else if(m==2){ // Unsigned 64bit Integer to IPv8 Format
			ull n;cin>>n;
			vector<int> v;
			for(int j=0;j<8;j++){
				string stemp = "";
				int itemp = 0;
				for(int i=0;i<8;i++){
					stemp+= ((n%2==0)?"0":"1");
					n /= 2;
				}
				while(stemp.length() > 0){
					itemp *= 2;
					if(*(stemp.end()-1) == '1'){
						itemp += 1;
					}
					stemp.pop_back();
				}
				v.push_back(itemp);
				
			}
			for_each(v.rbegin(),v.rend()-1,display);
			cout << *(v.begin()) << "\n";
		}
	}
	
	
}