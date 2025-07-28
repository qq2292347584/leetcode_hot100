#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> res;
    int st = -2e9, ed = -2e9;
    for(auto& interval : intervals)
    {
        if(ed < interval[0])
        {
            if(ed != -2e9) res.push_back({st, ed});
            st = interval[0], ed = interval[1];
        } else ed = max(ed, interval[1]);
    }
    if(ed != -2e9) res.push_back({st, ed});
    return res;
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>> intervals;
    for(int i = 0; i < n; i++)
    {
        int a,b;
        cin>>a>>b;
        intervals.push_back({a, b});
    }
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> ans = merge(intervals);
    for(auto& interval : ans)
    {
        cout<<interval[0]<<" "<<interval[1]<<endl;
    }
    return 0;
}


