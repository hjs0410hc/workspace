#include <bits/stdc++.h>
using namespace std;

int mat[101][101];
int n,l;
int ans =0;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    memset(mat,0,sizeof(mat));
    cin>>n>>l;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> mat[i][j];
        }
    }
    for(int j=0;j<n;j++){ // 가로를 한다.
        //cout << j+1 << "번 째 가로 줄 하는 중\n";
        int prev = mat[j][0];
        int len = 0;
        int len2 = 1;
        bool succ = true;
        for(int i=1;i<n;i++){
            if(mat[j][i] != prev){ // 높이가 전과 다르다
                if(abs(mat[j][i] - prev)>1){ // 전과 높이가 2 이상 차이난다 = FAIL
                    //cout << "전과 높이 2이상 차이로 실패\n";
                    succ=false;
                    break;
                }
                if(len>0){ // 남은 경사로의 길이가 있는데 높이가 달라졌다 = FAIL
                //+ 경사로를 놓다가 범위를 벗어나는경우.
                    //cout << "남은 경사로 길이 존재하나 높이가 달라져서 실패\n";
                    succ=false;
                    break;
                }
                if(mat[j][i] > prev && len2<l){ // 올라가는데 다음 경사로를 설치할 수가 없음
                    //cout << j << " " << i<< " : 올라가는데 다음 경사로 설치 불가능(len2>=l)\n";
                    succ=false;
                    break;
                }
                //여기까지왔다면 경사로 설치함
                if(mat[j][i] > prev){ //올라간다
                    len2=1;
                }else{ // 내려간다
                    len=l-1;
                    len2=0;
                }
                prev=mat[j][i];
            }else{
                if(len>0){
                    len--;
                }else{
                    len2++;
                }
            }
            
        }
        if(succ && len ==0){
            //cout << j+1 << "번 째 가로 줄 성공\n";
            ans++;
        }
        
    }
    for(int j=0;j<n;j++){ // 세로를 한다.
        //cout << j+1 << "번 째 세로 줄 하는 중\n";
        int prev = mat[0][j];
        int len = 0;
        int len2 = 1;
        bool succ = true;
        for(int i=1;i<n;i++){
            if(mat[i][j] != prev){ // 높이가 전과 다르다
                if(abs(mat[i][j] - prev)>1){ // 전과 높이가 2 이상 차이난다 = FAIL
                    //cout << "전과 높이 2이상 차이로 실패\n";
                    succ=false;
                    break;
                }
                if(len>0){ // 남은 경사로의 길이가 있는데 높이가 달라졌다 = FAIL
                //+ 경사로를 놓다가 범위를 벗어나는경우.
                    //cout << "남은 경사로 길이 존재하나 높이가 달라져서 실패\n";
                    succ=false;
                    break;
                }
                if(mat[i][j] > prev && len2<l){ // 올라가는데 다음 경사로를 설치할 수가 없음
                    //cout << i << " " << j<< " : 올라가는데 다음 경사로 설치 불가능(len2>=l) "<< len2 <<" "<< l<<" \n";
                    succ=false;
                    break;
                }
                //여기까지왔다면 경사로 설치함
                if(mat[i][j] > prev){ //올라간다
                    len2=1;
                }else{ // 내려간다
                    len=l-1;
                    len2=0;
                }
                prev=mat[i][j];
            }else{
                if(len>0){
                    len--;
                }else{
                    len2++;
                }
            }
        }
        if(succ && len ==0){
            //cout << j+1 << "번 째 세로 줄 성공\n";
            ans++;
        }
        
    }
    cout << ans;
}