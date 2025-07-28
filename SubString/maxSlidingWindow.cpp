//单调队列滑动窗口求最大值
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> res;
    vector<int> q(n + 1, 0);
    int hh = 0, tt = - 1;

    for(int i = 0; i < n; i++)
    {
        if(hh <= tt && i - q[hh] + 1 > k) hh++;
        while(hh <= tt && nums[q[tt]] <= nums[i]) tt--;
        q[++tt] = i;
        if(i + 1 >= k) res.push_back(nums[q[hh]]);
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    int k;
    cin >> k;

    vector<int> ans = maxSlidingWindow(nums, k);
    for(auto& x : ans) cout<<x<<" ";

    return 0;
}

