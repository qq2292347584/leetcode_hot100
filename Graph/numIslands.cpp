#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>

using namespace std;
const int N = 310;
bool st[N][N];
void bfs(vector<vector<char>>& grid, int sx, int sy)
{
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int,int>> q;
    q.push({sx, sy});
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    while(!q.empty())
    {
        auto t = q.front();
        q.pop();
        st[t.first][t.second] = true;

        for(int i = 0; i < 4; i++)
        {
            int x = t.first + dx[i];
            int y = t.second + dy[i];
            if(x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == '0') continue;
            if(st[x][y]) continue;

            st[x][y] = true;
            q.push({x, y});
        }
    }

}


int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    memset(st, false, sizeof st);
    int ans = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            if(grid[i][j] == '1' && !st[i][j])
            {
                bfs(grid, i, j);
                ans++;
            }
        }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            grid[i].push_back(c);
        }

    cout << numIslands(grid) << endl;
    return 0;
}

