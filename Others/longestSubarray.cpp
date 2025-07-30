//2419.按位与最大的最长字符串
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;
int longestSubarray(vector<int>& nums) {
    int n = nums.size();
    int max_nums = 0;
    for(int i = 0; i < n; i++) max_nums = max(max_nums, nums[i]);

    int ans = 0;
    int j = 0;
    for(int i = 0; i < n; i++)
    {
        int x = nums[i];
        if(x == max_nums)
        {
            j = i;
            while(j < n && nums[j] == max_nums) j++;
            ans = max(ans, j - i);
            i = j - 1;
        }
    }

    return ans;
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
    cout << longestSubarray(nums) << endl;
    return 0;
}
