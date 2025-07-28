//11.盛最多水的容器
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;

int maxArea(vector<int>& height) {
    int n = height.size();
    int ans = 0;
    int l = 0, r = n - 1;

    while(l <= r)
    {
        int t = height[l] < height[r] ? height[l] * (r - l++) : height[r] * (r-- - l);
        ans = max(ans, t);
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> height;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        height.push_back(x);
    }

    cout << maxArea(height) << endl;
    return 0;
}

