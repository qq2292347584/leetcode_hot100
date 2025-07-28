//73.矩阵置零
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;
void setZeroes(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<bool> rows(n, false);
    vector<bool> cols(m, false);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            if(!matrix[i][j])
            {
                rows[i] = true;
                cols[j] = true;
            }
        }

    for(int i = 0; i < n; i++)
    {
        if(rows[i])
        {
            for(int j = 0; j < m; j++)
                matrix[i][j] = 0;
        }
    }

    for(int j = 0; j < m; j++)
    {
        if(cols[j])
        {
            for(int i = 0; i < n; i++)
                matrix[i][j] = 0;
        }
    }

}
int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }

    setZeroes(matrix);

    for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

