#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    //前缀和
    vector<int> s(n + 1, 0);
    for(int i = 0; i < n; i++) s[i + 1] = s[i] + nums[i];

    int min_pre = 0;
    int ans = -2e9;
    for(int i = 0; i < n; i++)
    {
        ans = max(ans, s[i + 1] - min_pre);
        min_pre = min(min_pre, s[i + 1]);
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    cout << maxSubArray(arr) << endl;
    return 0;
}
