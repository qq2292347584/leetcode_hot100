//54. 螺旋矩阵
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> ans(n * m, 0);
    int direct = 0; // 用来控制方向
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    int cnt = 0;

    int x = 0, y = 0;
    vector<vector<bool>> st(n, vector<bool>(m, false));
    while(cnt < n * m)
    {
        ans[cnt++] = matrix[x][y];
        st[x][y] = true;
        int tx = x + dx[direct];
        int ty = y + dy[direct];
        while(tx < 0 || tx >= n || ty < 0 || ty >= m || st[tx][ty])
        {
            direct = (direct + 1) % 4;
            tx = x + dx[direct];
            ty = y + dy[direct];
            if(cnt == n * m) break;
        }
        x = tx;
        y = ty;
    }

    return ans;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> matrix[i][j];

    vector<int> ans = spiralOrder(matrix);
    for(auto& x : ans) cout << x << " ";
    cout << endl;
    return 0;
}