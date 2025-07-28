//128.最长连续子序列
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<set>

using namespace std;

int longestConsecutive(vector<int>& nums) {
    set<int> st(nums.begin(), nums.end()); //利用set进行排序 + 去重
    vector<int> arr(st.begin(), st.end());
    int n = arr.size();
    int ans = 0;
    for(int l = 0, r = 0; l < n; l++)
    {
        r = l;
        while(r + 1 < n && arr[r] + 1 == arr[r + 1]) r++;
        ans = max(ans, r - l + 1);
        l = r;
    }
    return ans;
}

int main()
{
    int n;
    vector<int> nums;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    cout << longestConsecutive(nums) << endl;
    return 0;
}
