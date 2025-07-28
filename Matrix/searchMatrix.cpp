//240.搜索二维矩阵II
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(matrix[i][j] == target)
                return true;
    return false;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> matrix[i][j];
    int target;
    cin >> target;
    cout << searchMatrix(matrix, target) << endl;
    return 0;
}

