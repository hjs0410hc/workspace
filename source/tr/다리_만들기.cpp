#include <bits/stdc++.h>
using namespace std;

int n;
int arr[101][101];

int color[101][101];
bool visited[101][101];
int curcolor = 0;

struct xy
{
    int x, y;
};

xy dxdy[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

vector<vector<xy>> vxy(10001);

bool check(int x, int y)
{
    return (x >= 0 && y >= 0 && x < n && y < n);
}

void bfs(int x, int y)
{
    queue<xy> qpii;
    qpii.push({x, y});
    while (!qpii.empty())
    {
        xy f = qpii.front();
        color[f.x][f.y] = curcolor;
        vxy[curcolor].push_back({f.x, f.y});
        qpii.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = f.x + dxdy[i].x;
            int ny = f.y + dxdy[i].y;
            if (check(nx, ny) && !visited[nx][ny] && arr[nx][ny] == 1)
            {
                qpii.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j] && arr[i][j] == 1)
            {
                curcolor++;
                bfs(i, j);
            }
        }
    }
    int ans = 2e9;
    for (int i = 1; i <= curcolor; i++)
    { // 첫번째컬러
        for (int j = 1; j <= curcolor; j++)
        { // 두번째컬러
            if (i == j)
                continue;
            for (int k = 0; k < vxy[i].size(); k++)
            {
                for (int p = 0; p < vxy[j].size(); p++)
                {
                    ans = min(ans, abs(vxy[i][k].x - vxy[j][p].x) + abs(vxy[i][k].y - vxy[j][p].y) - 1);
                }
            }
        }
    }
    cout << ans;
}