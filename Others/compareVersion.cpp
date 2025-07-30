//165. 比较版本号
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;
//1.2 1.10 ----> -1
//1.01 1.001 ----> 0
//1.0  1.0.0.0 ----> 0
typedef long long ll;

vector<ll> getNums(string str)
{
    int n = str.size();
    vector<ll> ans;
    int x = 0;
    for(int l = 0, r = 0; l < n; l++)
    {
        r = l;
        while(r < n && str[r] != '.')
        {
            x = x * 10 + str[r++] - '0';
        }
        ans.push_back(x);
        x = 0;
        l = r;
    }

    return ans;
}

int compareVersion(string version1, string version2) {
    vector<ll> v1 = getNums(version1);
    vector<ll> v2 = getNums(version2);

    int n = v1.size();
    int m = v2.size();
    for (int i = 0; i < min(n, m); i++) {
        if (v1[i] < v2[i]) return -1;
        else if (v1[i] > v2[i]) return 1;
    }

    if(n > m) {
        for (int i = m; i < n; i++) {
            if(v1[i] > 0) return 1;
        }
    } else if(n < m) {
        for (int i = n; i < m; i++) {
            if(v2[i] > 0) return -1;
        }
    }
    return 0;
}
int main()
{
    string version1;
    string version2;
    cin >> version1 >> version2;

    cout << compareVersion(version1, version2) << endl;
    return 0;
}
