//49.字母异位词分组
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<unordered_map>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    int n = strs.size();
    unordered_map<string, vector<int>> hash;
    for(int i = 0; i < n; i++)
    {
        string str = strs[i];
        sort(str.begin(), str.end());
        hash[str].push_back(i);
    }

    vector<vector<string>> ans;
    for(auto& [k, v] : hash)
    {
        vector<string> res;
        for(auto& x : v) res.push_back(strs[x]);
        ans.push_back(res);
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<string> strs;
    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        strs.push_back(str);
    }

    vector<vector<string>> ans = groupAnagrams(strs);

    for(auto& item : ans)
    {
        for(auto& x : item)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}
