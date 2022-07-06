#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int prefix_idx = 0;
        string prefix = "";
        bool break_flag=false;
        // find length of shortest string
        int min_length = INT_MAX;
        for(int i=0; i < strs.size(); ++i)
        {
            min_length = min(min_length, (int)strs[i].length());
        }
        while(prefix_idx <= min_length)
        {
            char cur_char;
            for(int i=0 ; i < strs.size(); ++i)
            {
                if(prefix_idx == strs[i].length())
                {
                    break_flag = true;
                    break;
                }
                if(i==0)
                {
                    cur_char = strs[i][prefix_idx];
                    continue;
                }
                else
                {
                    if(cur_char != strs[i][prefix_idx])
                    {
                        break_flag = true;
                        break;
                    }
                }
            }

            if(break_flag)
            {
                break;
            }
            else
            {
                prefix_idx++;
                prefix += cur_char;
            }
        }

        return prefix;
    }
};

int main() {
    Solution s;
    vector<string> strs = {"flower","flow","flight"};
    cout << s.longestCommonPrefix(strs) << endl;
    return 0;
}
