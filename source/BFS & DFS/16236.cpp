#include <bits/stdc++.h>
using namespace std;

int x,n,ans{0};
int mat[21][21];
int currentSize = 2;
int currentEat = 0;
pair<int,int> curPos;

struct Fish{
    int dist,x,y,size;
};
class Comparator{
    public:
    bool operator()(Fish& f1, Fish& f2){
        if(f1.dist == f2.dist){
            if(f1.x == f2.x){
                return f1.y > f2.y;
            }else{
                return f1.x > f2.x;
            }
        }else{
            return f1.dist > f2.dist;
        }
    }
};
priority_queue<Fish,vector<Fish>,Comparator> pq;

bool visited[21][21]{0,};
pair<int,int> dxdy[4] = {{-1,0},{0,-1},{1,0},{0,1}};

struct Move{
    int x,y,dist;
};

bool boundaryCheck(int x,int y){
    return x >= 0 && y >= 0 && x < n && y < n;
}

void findFish(pair<int,int> p){
    memset(visited,0,sizeof(visited));
    visited[p.first][p.second] = true;
    queue<Move> q;
    q.push({p.first,p.second,0});
    while(!q.empty()){
        Move cur = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx = cur.x + dxdy[i].first;
            int ny = cur.y + dxdy[i].second;
            int ndist = cur.dist;

            if(boundaryCheck(nx,ny) && mat[nx][ny] <= currentSize && !visited[nx][ny]){
                ndist++;
                visited[nx][ny] = true;
                if(mat[nx][ny] != 0 && mat[nx][ny] < currentSize){ // 먹을 수 있음.
                    pq.push({ndist,nx,ny,mat[nx][ny]});
                }
                q.push({nx,ny,ndist});
            }
        }
    }
}

void solve(pair<int,int> pos){
    findFish(pos);
    while(!pq.empty()){
        Fish top =  pq.top();
        pq.pop();
        mat[top.x][top.y] = 0;
        ans += top.dist;
        if(++currentEat == currentSize){
            currentEat = 0;
            currentSize++;
        }
        pq = priority_queue<Fish,vector<Fish>,Comparator>();
        findFish({top.x,top.y});
    }
}


int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    memset(mat,0,sizeof(mat));
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> x;
            if(x != 0){
                if(x==9){
                    curPos = {i,j};
                }else{
                    mat[i][j] = x;
                }
            }
        }
    }
    solve(curPos);
    cout << ans;
}