//s[i] - s[j] = k
//s[j] = s[i] - k
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<unordered_map>

using namespace std;

int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> s(n + 1, 0);
    for(int i = 0; i < n; i++) s[i + 1] = s[i] + nums[i];
    unordered_map<int,int> cnt;
    cnt[0] = 1;

    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        ans +=cnt[s[i + 1] - k];
        cnt[s[i + 1]]++;
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

    int k;
    cin >> k;
    cout << subarraySum(nums, k) << endl;
    return 0;
}
