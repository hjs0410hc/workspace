#include <bits/stdc++.h>
using namespace std;

#define ONGOING 0
#define WIN 1
#define FAIL 2

struct status{
    status(pair<int,int> _rLoc,pair<int,int> _bLoc) : rLoc{_rLoc},bLoc{_bLoc},trials{0} {;}
    status(pair<int,int> _rLoc,pair<int,int> _bLoc,int _trials,int _state) : rLoc{_rLoc},bLoc{_bLoc},trials{trials},state{_state} {;}
    pair<int,int> rLoc;
    pair<int,int> bLoc;
    int trials;
    int state = 0; // 0 : ONGOING 1 : WIN 2 : FAIL
};

char mat[11][11];
int n,m;
pair<int,int> firstRLoc,firstBLoc;
queue<status> q;

// 0 북 1 동 2 남 3 서
pair<int,int> dir[4] = {{-1,0},{0,-1},{1,0},{0,1}};

// R,B의 위치가 겹치는 경우 없애야함 <- 어케구현하노 ㅋ
// R,B가 동시에 O로 가는 경우 FAIL
// B만 O로 가는 경우 FAIL
// R만 O로 가는 경우 WIN

status MOVE(status& s,int dirNum){
    pair<int,int> bLoc = s.bLoc;
    pair<int,int> rLoc = s.rLoc;
    int trials = s.trials;
    int state = s.state;
    
    pair<int,int> bNext = {bLoc.first + dir[dirNum].first, bLoc.second + dir[dirNum].second};
    pair<int,int> rNext = {rLoc.first + dir[dirNum].first, rLoc.second + dir[dirNum].second};
    
    





    return status(bLoc,rLoc,trials,state);
}

/* status MOVE(status& s,int dirNum){
    pair<int,int> bLoc = s.bLoc;
    pair<int,int> rLoc = s.rLoc;
    int trials = s.trials;
    int state = s.state;
    while(mat[bLoc.first + dir[dirNum].first][bLoc.second + dir[dirNum].second] != '#'){
        if(mat[bLoc.first + dir[dirNum].first][bLoc.second + dir[dirNum].second] != 'O'){
            state = 1;
            break;
        }
        bLoc.first += dir[dirNum].first;
        bLoc.second += dir[dirNum].second;
    }
    while(mat[rLoc.first + dir[dirNum].first][rLoc.second + dir[dirNum].second] != '#'){
        if(mat[rLoc.first + dir[dirNum].first][rLoc.second + dir[dirNum].second] != 'O'){

        }
        rLoc.first += dir[dirNum].first;
        rLoc.second += dir[dirNum].second;
    }
    return status(bLoc,rLoc,trials,state);
} */


vector<status> winningcase;
void BFS(pair<int,int> rLoc, pair<int,int> bLoc){
    q.push(status(rLoc,bLoc));
    while(!q.empty()){
        status target = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            status moved = MOVE(target,i);
            if(moved.state == WIN){
                winningcase.push_back(moved);
            }else if(moved.state == ONGOING && moved.trials < 10){
                q.push(moved);
            }
        }
    }
}

bool comparator(status& p1, status& p2){
    return p1.trials < p2.trials;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n>>m;
    for(int i=0;i<n;i++){
        string s;cin>>s;
        for(int j=0;j<m;j++){
            if(s[j] == 'R'){
                firstRLoc = {i,j};
                mat[i][j] = '.';
            }else if(s[j] == 'B'){
                firstBLoc = {i,j};
                mat[i][j] = '.';
            }
            else mat[i][j] = s[j];
        }
    }
    BFS(firstRLoc,firstBLoc);
    sort(winningcase.begin(),winningcase.end(),comparator);
    
    cout << winningcase[0].trials;
}