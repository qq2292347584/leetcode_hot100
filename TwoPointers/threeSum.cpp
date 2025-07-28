//15.三数之和
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    //注意先要对整个数组进行从小到大排序
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> ans;

    for(int i = 0; i < n - 2; i++)
    {
        int x = nums[i];
        if(i > 0 && x == nums[i - 1]) continue;
        int l = i + 1;
        int r = n - 1;
        while(l < r)
        {
            if(nums[l] + nums[r] > -x) r--;
            else if(nums[l] + nums[r] < -x) l++;
            else {
                ans.push_back({x, nums[l], nums[r]});
                l++;
                while(l < r && nums[l] == nums[l - 1]) l++;
                r--;
                while(l < r && nums[r] == nums[r + 1]) r--;
            }
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

    vector<vector<int>> ans = threeSum(nums);

    for(auto& item : ans)
    {
        for(auto& x : item)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}