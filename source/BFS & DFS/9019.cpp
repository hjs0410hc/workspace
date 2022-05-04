#include <bits/stdc++.h>
using namespace std;

int tc,a,b;

struct solve{
	int prev;
	char c;
};

solve visited[10001]{0,}; // 어떤 숫자에서 왔는가?

int funcD(int src){
	return (src*2)%10000;
}

int funcS(int src){
	return ((src-1 < 0)? 9999:src-1);
}

int funcL(int src){
	int msd = src/1000;
	src *= 10;
	src -= msd*10000;
	src += msd;
	return src;
}

int funcR(int src){
	int lsd = src%10;
	src /= 10;
	src += 1000*lsd;
	return src;
}

string findAns(int fin){
	string s = "";
	while(fin != a){
		s += visited[fin].c;
		fin = visited[fin].prev;
	}
	return s;
}

void bfs(int init){
	queue<int> q;
	q.push(init);
	while(!q.empty()){
		int t = q.front();
		q.pop();
		if(t==b){
			string ans = findAns(t);
			reverse(ans.begin(),ans.end());
			cout << ans << "\n";
			break;
		}else{
			int calc = funcD(t);
			if(!visited[calc].c){
				visited[calc].prev = t;
				visited[calc].c='D';
				q.push(calc);
			}
			calc = funcS(t);
			if(!visited[calc].c){
				visited[calc].prev = t;
				visited[calc].c='S';
				q.push(calc);
			}
			calc = funcL(t);
			if(!visited[calc].c){
				visited[calc].prev = t;
				visited[calc].c='L';
				q.push(calc);
			}
			calc = funcR(t);
			if(!visited[calc].c){
				visited[calc].prev = t;
				visited[calc].c='R';
				q.push(calc);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>tc;
	while(tc--){
		memset(visited,0,sizeof(solve)*10001);
		cin>>a>>b;
		bfs(a);
	}
	
}