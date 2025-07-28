#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k %= n;
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
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
    rotate(nums, k);

    for(auto& x : nums) cout<<x<<" ";

    return 0;
}
