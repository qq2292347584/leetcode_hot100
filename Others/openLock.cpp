//LCR109. 打开转盘锁

//输入：deadends = ["0201","0101","0102","1212","2002"], target = "0202"
//输出：6
//解释：
//可能的移动序列为 "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202"。
//注意 "0000" -> "0001" -> "0002" -> "0102" -> "0202" 这样的序列是不能解锁的，因为当拨动到 "0102" 时这个锁就会被锁定输入：deadends = ["0201","0101","0102","1212","2002"], target = "0202"
//输出：6
//解释：
//可能的移动序列为 "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202"。
//注意 "0000" -> "0001" -> "0002" -> "0102" -> "0202" 这样的序列是不能解锁的，因为当拨动到 "0102" 时这个锁就会被锁定

#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;
typedef pair<string,int> PSI;

int openLock(vector<string>& deadends, string target) {
    int n = deadends.size();
    unordered_set<string> st(deadends.begin(), deadends.end());
    unordered_map<string,bool> visited;

    if(st.count("0000")) {
        return -1;
    }

    queue<PSI> q;
    q.push({"0000", 0});
    visited["0000"] = true;

    while(!q.empty())
    {
        PSI t = q.front();
        q.pop();
        string str = t.first;
        int step = t.second;

        if(str == target) return step;

        for(int i = 0; i < 4; i++)
        {
            char original_char = str[i];
            //向右转
            string right_str = str;
            right_str[i] = ((original_char - '0' + 1) % 10) + '0';

            if(!visited[right_str] && st.find(right_str) == st.end()){
                visited[right_str] = true;
                q.push({right_str, step + 1});
            }


            //向左转
            string left_str = str;
            left_str[i] = ((original_char - '0' - 1 + 10) % 10) + '0';
            if(!visited[left_str] && st.find(left_str) == st.end()) {
                visited[left_str] = true;
                q.push({left_str, step + 1});
            }


        }
    }

    return -1;
}

int main()
{
    vector<string> deadends;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        deadends.push_back(str);
    }

    string target;
    cin >> target;
    cout << openLock(deadends, target) << endl;

    return 0;
}
