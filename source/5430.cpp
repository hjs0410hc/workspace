#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--){
		string p;cin>>p;
		int n;cin>>n;
		bool error = false;
		bool reversal = false;
		deque<string> dq;

		string input; cin >> input;
		if (input != "[]") {
			int prev = 0, cur;
			input = input.substr(1, input.length() - 1);
			input = input.substr(0, input.length() - 1);
			cur = input.find(',');
			while (cur != string::npos) {
				string substr = input.substr(prev, cur - prev);
				dq.push_back(substr);
				prev = cur + 1;
				cur = input.find(',', prev);
			}
			dq.push_back(input.substr(prev, cur - prev));
		} // deque 에 입력완료
		
		for(int i=0;i<p.length();i++){
			if(p[i]=='R'){
				reversal = !reversal;
			}else if(p[i]=='D'){
				if(!dq.empty()){
					if(!reversal){
						dq.pop_front();
					}else{
						dq.pop_back();
					}
				}else{
					error = true;
				}
			}
		}
		if(error){
			cout << "error\n";
		}else if(dq.empty()){cout << "[]\n";}else{
			cout << '[';
			if(!reversal){
				while(dq.size() != 1){
					cout << dq.front() << ",";
					dq.pop_front();
				}
				cout << dq.front() << ']';
			}else{
				while(dq.size() != 1){
					cout << dq.back() << ",";
					dq.pop_back();
				}
				cout << dq.back() << ']';
			}
			cout << '\n';
		}
		
	}
	
	
}