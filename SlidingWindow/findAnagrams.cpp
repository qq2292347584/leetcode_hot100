//438.找到字符串中所有字母异位词
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;

bool check(vector<int>& a, vector<int>& b)
{
    for(int i = 0; i < 26; i++)
    {
        if(a[i] != b[i]) return false;
    }
    return true;
}

vector<int> findAnagrams(string s, string p) {
    vector<int> ans;
    vector<int> cnt_s(26, 0);
    vector<int> cnt_p(26, 0);
    int n = s.size();
    int m = p.size();

    for(int i = 0; i < m; i++) cnt_p[p[i] - 'a']++;

    for(int i = 0; i < n; i++)
    {
        cnt_s[s[i] - 'a']++;
        if(i < m - 1) continue;
        if(check(cnt_s, cnt_p)) ans.push_back(i - m + 1);
        cnt_s[s[i - m + 1] - 'a']--;
    }

    return ans;

}
int main()
{
    string s, p;
    cin >> s >> p;

    vector<int> ans = findAnagrams(s, p);
    for(auto& x : ans) cout << x << " ";
    return 0;
}

