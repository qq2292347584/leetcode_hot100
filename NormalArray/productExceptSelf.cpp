#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> res;
    vector<int> pre(n + 1, 1);
    vector<int> after(n + 1, 1);

    for(int i = 0; i < n; i++) pre[i + 1] = pre[i] * nums[i];
    for(int i = n - 1; i >= 0; i--) after[i] = after[i + 1] * nums[i];

    for(int i = 0; i < n; i++)
    {
        int t = pre[i] * after[i + 1];
        res.push_back(t);
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

    vector<int> ans = productExceptSelf(nums);
    for(auto& x : ans) cout<<x<<" ";

    return 0;
}

