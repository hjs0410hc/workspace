#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int tc,n;

vector<vector<int>> v;

void Combination(vector<int> arr, vector<int> comb, int r, int index, int depth)
{
    if (r == 0)
    {
        v.push_back(comb);
    }
    else if (depth == arr.size())
    {
        return;
    }
    else
    {
        comb[index] = arr[depth];
        Combination(arr, comb, r - 1, index + 1, depth + 1);
        // nCr 분해
        Combination(arr, comb, r, index, depth + 1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> tc;
    while(tc--){
        cin>>n;int r = n/2;
        vector<pair<ll,ll>> vp;int x,y;
        for(int i=0;i<n;i++){//20.
            cin>>x>>y;
            vp.push_back({x,y});
        }
        vector<int> s;
        for(int i=0;i<n;i++){ //20.
            s.push_back(i);
        }
        double mini = 2e9;
        vector<int> comb(r);
        Combination(s,comb,r,0,0);
        for(int i=0;i<v.size();i++){ //184756
            //v 안에 있는건 더하고 v안에 없는건 뺄거다.
            bool visited[21];
            memset(visited,0,sizeof(visited));
            ll xSum = 0;
            ll ySum = 0;
            for(int j=0;j<v[i].size();j++){
                //cout << v[i][j] << " is adding\n";
                xSum += vp[v[i][j]].first;
                ySum += vp[v[i][j]].second;
                visited[v[i][j]] = true;
            }
            for(int j=0;j<n;j++){
                if(!visited[j]){
                    //cout << j << "is removing\n";
                    xSum -= vp[j].first;
                    ySum -= vp[j].second;
                }
            }
            double calc = sqrt(xSum*xSum+ySum*ySum);
            if (calc < mini){
                mini = calc;
            }
        }
        cout << fixed << setprecision(15)<<mini<<"\n";

        v.clear();
 /*        do{
            ll xSum = 0;
            ll ySum = 0;
            for(int i=0;i<n;i++){ //20
                if(i%2==0){
                    //cout << s[i] << "::"<<vp[s[i]-'0'].first << " " <<vp[s[i]-'0'].second << "added\n";
                    xSum += vp[s[i]].first;
                    ySum += vp[s[i]].second;
                }else{
                    //cout <<s[i] << "::"<<vp[s[i]-'0'].first << " " <<vp[s[i]-'0'].second << "rem\n";
                    xSum -= vp[s[i]].first;
                    ySum -= vp[s[i]].second;
                }
            }
            double calct = sqrt(xSum*xSum+ySum*ySum);
            if(calct < mini){
                mini = calct;
            }
            
        }while(next_permutation(s.begin(),s.end())); // 20
        cout << fixed << setprecision(15)<<mini<<"\n"; */
    }
    
    
}