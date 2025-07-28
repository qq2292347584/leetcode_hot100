//无重复字符的最长子串
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<unordered_map>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int n = s.size();
    unordered_map<char,int> cnt;
    int ans = 0;
    for(int l = 0, r = 0; r < n; r++)
    {
        cnt[s[r]]++;
        while(l <= r && cnt[s[r]] >= 2) cnt[s[l++]]--;
        ans = max(ans, r - l + 1);
    }
    return ans;
}
int main()
{
    string s;
    cin >> s;
    cout << lengthOfLongestSubstring(s) << endl;
}

