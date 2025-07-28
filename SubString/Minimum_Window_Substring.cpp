//首先这个是滑动窗口的长度越长越合法
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<unordered_map>

using namespace std;

bool check(unordered_map<char,int>& a, unordered_map<char,int>& b)
{
    for(int i = 'a'; i <= 'z'; i++)
    {
        if(a[i] < b[i]) return false;
    }
    for(int i = 'A'; i <= 'Z'; i++)
    {
        if(a[i] < b[i]) return false;
    }
    return true;
}

string minWindow(string s, string t) {
    int n = s.size();
    int m = t.size();
    unordered_map<char,int> cnts;
    unordered_map<char,int> cntt;

    for(int i = 0; i < m; i++) cntt[t[i]]++;
    int min_len = n + 1;
    int index = 0;

    for(int l = 0, r = 0; r < n; r++)
    {
        cnts[s[r]]++;
        while(r - l + 1 >= m && check(cnts, cntt))
        {
            int len = r - l + 1;
            if (len < min_len) {
                min_len = len;
                index = l;
            }
            cnts[s[l++]]--;
        }
    }

    return min_len == n + 1 ? "" : s.substr(index, min_len);
}
int main()
{
    string s;
    string t;
    cin >> s >> t;

    cout << minWindow(s, t) << endl;
}

