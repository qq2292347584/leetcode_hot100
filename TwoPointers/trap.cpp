//42.接雨水
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;

int trap(vector<int>& height) {
    int n = height.size();
    int pre_max = 0, after_max = 0;
    int l = 0, r = n - 1;
    int ans = 0;

    while(l <= r)
    {
        pre_max = max(pre_max, height[l]);
        after_max = max(after_max, height[r]);
        if(pre_max < after_max) ans += pre_max - height[l++];
        else ans += after_max - height[r--];
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

    cout << trap(height) << endl;
    return 0;
}
