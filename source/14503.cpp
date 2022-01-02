#include <bits/stdc++.h>
using namespace std;

int mat[50][50];
int n,m,r,c,d; // n=세로크기 m=가로크기 r=현재row c=현재col d=direction
int countingstar = 0;
pair<int,int> dxdy[4]={{0,-1},{-1,0},{0,1},{1,0}};
pair<int,int> dxdyz[4]={{1,0},{0,-1},{-1,0},{0,1}};
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    memset(mat,0,sizeof(mat));
    cin >> n>> m;
    cin >> r >> c >> d;
    for(int i=0;i<n;i++){ // MATRIX 입력
        for(int j=0;j<m;j++){
            cin >> mat[i][j];
        }
    }
    // isClear : 4면이 벽/깔끔 // isStuck : 후진불가능
    bool isClear{false},isStuck{false};
    int failCount{0};
    while(!isClear || !isStuck){
        if(mat[r][c] == 0){ // 현재위치 0일때 청소함
            mat[r][c] = 2;
            countingstar++;
            //cout << "청소함: (" << r << ", " << c << ")  cs:"  << countingstar << "\n";
        }
        if(r+dxdy[d].first >= 0 && r+dxdy[d].first < n && c+dxdy[d].second >= 0 && c+dxdy[d].second < m &&mat[r+dxdy[d].first][c+dxdy[d].second]==0){
            // 왼쪽에 청소할 공간 있으면 회전 후 전진
            r += dxdy[d].first;
            c += dxdy[d].second;
            d = (d-1<0) ? 3 : d-1; // 0,3,2,1
            isClear = false;
            failCount = 0;
        }else{ // 왼쪽청소구간없음
            if(failCount > 3){
                //4면을 다돌았을때 청소할 구역 없을 경우
                isClear = true;
                if(r+dxdyz[d].first >= 0 && r+dxdyz[d].first < n && c+dxdyz[d].second >= 0 && c+dxdyz[d].second < m && mat[r+dxdyz[d].first][c+dxdyz[d].second] != 1){
                    //후진가능
                    r+=dxdyz[d].first;
                    c+=dxdyz[d].second;
                    //후진했으므로 조건초기화
                    isClear = false;
                    failCount = 0;
                }else{
                    //후진불가능
                    isStuck = true; // 종료.
                }
            }else{
                d = (d-1<0) ? 3 : d-1; // 0,3,2,1
                failCount++;
            }
        }
        
    }
    cout << countingstar;
}