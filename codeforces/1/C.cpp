// ps-solving code for C
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    multiset<int> tasksSet;
    int tasks[200001]{0,};
    int n, m;
    cin>> n >>m;
    for (int i=0;i<m;i++)
    {
        int x;
        cin >> x;
        tasks[x]++;
    }
    for (int i=1; i<=n;i++)
    {
        tasksSet.insert(tasks[i]);
    }
    if (tasksSet.size() > 1) // 일꾼이 한명일때
        while ((*tasksSet.rbegin()) > *(tasksSet.begin()) + 2) // 바꿀 필요가 있는 경우
        {
            int r = *(tasksSet.rbegin());
            int l = *(tasksSet.begin());
            tasksSet.erase(--tasksSet.end());
            tasksSet.erase(tasksSet.begin());
            tasksSet.insert(r - 1);
            tasksSet.insert(l + 2);
        }
    cout << *(tasksSet.rbegin()) << "\n";
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}