#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--){
		int m;char c;cin>>m>>c;
		for(int i=0;i<m;i++){
			if(c == 'C'){ // Alphabet to NUM
				char ic;cin>>ic;
				cout << ic-'A'+1 << " ";
			}else if(c == 'N'){ // NUM to Alphabet
				int ic;cin>>ic;
				cout << char(ic+'A'-1) <<" ";
			}
		}
		cout << "\n";
	}
	
	
}