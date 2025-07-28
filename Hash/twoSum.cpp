//1.两数之和
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    unordered_map<int,int> hash;
    for(int i = 0; i < n; i++)
    {
        if(hash.contains(target - nums[i]))
        {
            return {hash[target - nums[i]], i};
        }
        hash[nums[i]] = i;
    }
    return {};
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

    int target;
    cin >> target;

    vector<int> ans = twoSum(nums, target);
    for(auto& x : ans) cout << x << " ";
    cout << endl;
    return 0;
}

