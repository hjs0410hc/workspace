#include <bits/stdc++.h>
using namespace std;

int n,a,b;
struct seat{
    int x;
    int y;
    int adjNum;
};

vector<int> seq;
bool graph[402][402]{0};
int mat[22][22]{0}; // r=c=0은 사용하지 않는다.
pair<int,int> dxdy[4]= {{1,0},{0,1},{-1,0},{0,-1}};

bool checkBound(int x,int y){
    return (x>0&&y>0&&x<=n&&y<=n);
}

vector<seat> cond1(int cur){ // 3
    vector<seat> v;
    int maxCount = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(mat[i][j])continue;
            //cout << i << " " << j << " 자리 확인 중\n";
            int count = 0; // 인접한 친구 수
            int adjNum = 0; // 인접한 빈 공간 수
            for(int k=0;k<4;k++){
                int nx = i+dxdy[k].first;
                int ny = j+dxdy[k].second;
                if(checkBound(nx,ny)){
                    if(graph[cur][mat[nx][ny]]){
                        count++;
                    }
                    if(!mat[nx][ny]){
                        adjNum++;
                    }
                }
            }
            //cout << count << " " << adjNum << "\n";
            if(count > maxCount){
                v.clear();
                maxCount = count;
            }
            if(count == maxCount)v.push_back({i,j,adjNum});
        }
    }
    return v;
}

vector<seat> cond2(const vector<seat>& v1){
    int maxAdjNum = 0;
    vector<seat> v2;
    for(int i=0;i<v1.size();i++){
        if(v1[i].adjNum > maxAdjNum){
            maxAdjNum = v1[i].adjNum;
            v2.clear();
        }
        if(v1[i].adjNum == maxAdjNum){
            v2.push_back(v1[i]);
        }
    }
    return v2;
}

bool comparator(const seat& s1, const seat& s2){
    if(s1.x == s2.x){
        return s1.y < s2.y;
    }else{
        return s1.x < s2.x;
    }
}


int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    for(int i=0;i<n*n;i++){
        cin >> a;
        seq.push_back(a);
        for(int j=0;j<4;j++){
            cin >> b;
            graph[a][b] = true;
        }
    }

    mat[2][2] = seq[0];

    for(int k=1;k<n*n;k++){
        int i = seq[k];
        //cout << i << " 처리중\n";
        vector<seat> v1 = cond1(i);
        /* cout << "v1에 있는 자리?:";
        for(seat& s : v1){
            cout << "{" << s.x << ", " << s.y << "}, ";
        }
        cout << "\n"; */
        if(v1.size() > 1){
            vector<seat> v2 = cond2(v1);
            /* cout << "v2에 있는 자리?:";
            for(seat& s : v2){
                cout << "{" << s.x << ", " << s.y << "}, ";
            }
            cout << "\n"; */
            if(v2.size() >1){
                sort(v2.begin(),v2.end(),comparator);
                //cout << "조건3에서 결정: "<<v2[0].x << " " << v2[0].y << "\n";
                mat[v2[0].x][v2[0].y] = i;
            }else{
                mat[v2[0].x][v2[0].y]=i;
            }
        }else{
            mat[v1[0].x][v1[0].y]=i;
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int count = 0;
            for(int k=0;k<4;k++){
                int nx=i+dxdy[k].first;
                int ny=j+dxdy[k].second;
                if(checkBound(nx,ny) && graph[mat[i][j]][mat[nx][ny]]){
                    count++;
                }
            }
            ans += pow(10,count-1);
        }
    }
    cout << ans;
}