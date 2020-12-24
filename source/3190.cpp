#include <bits/stdc++.h>
#define VACANT 0
#define APPLE 1
#define SNAKE 2
using namespace std;

int n,ans;
int mapd[101][101];
int length = 1;
queue<pair<int,int>> snakecoord;
pair<int,int> curheading = {0,1};
pair<int,int> curpos = {1,1};
bool FIN = false;


void MOVE(){
	curpos.first += curheading.first;
	curpos.second += curheading.second;
	if(mapd[curpos.first][curpos.second] == APPLE){
		mapd[curpos.first][curpos.second] = SNAKE;
		snakecoord.push({curpos.first,curpos.second});
	}else if(curpos.first > n || curpos.second > n || curpos.first < 1 || curpos.second < 1){
		FIN = true;
		return;
	}else if(mapd[curpos.first][curpos.second] == SNAKE){
		FIN = true;
		return;
	}else{
		mapd[curpos.first][curpos.second] = SNAKE;
		snakecoord.push({curpos.first,curpos.second});
		pair<int,int> tailcoord = snakecoord.front();
		snakecoord.pop();
		mapd[tailcoord.first][tailcoord.second] = VACANT;
	}
	
}

void changeDirection(char C){
	if(C=='L'){
		if(curheading.first == 0){
			curheading.first = -curheading.second;
			curheading.second = 0;
		}else{
			curheading.second = curheading.first;
			curheading.first = 0;
		}
	}else if(C=='D'){
		if(curheading.first == 0){
			curheading.first = curheading.second;
			curheading.second = 0;
		}else{
			curheading.second = -curheading.first;
			curheading.first = 0;
		}

	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	snakecoord.push({1,1});
	mapd[1][1] = SNAKE;
	int k;cin>>n>>k;
	for(int i=0;i<k;i++){
		int r,c;cin>>r>>c;
		mapd[r][c] = APPLE;
	}
	int l;cin>>l;
	for(int i=0;i<l;i++){
		int X;char C;cin>>X>>C;
		while(ans < X){
			//cout << curpos.first << "," << curpos.second << " : " << ans << "\n";
			ans++;
			MOVE();
			if(FIN){
				cout << ans;
				return 0;
			}
		}
		changeDirection(C);
	}
	while(!FIN){
		//cout << curpos.first << "," << curpos.second << " : " << ans << "\n";
		ans++;
		MOVE();
	}
	cout << ans;
	return 0;
}