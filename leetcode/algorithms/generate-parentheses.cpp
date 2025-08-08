#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void generateParenthesis(int n, int open, int close, string s, vector<string> &ans)
    {
        if (open == n and close == n)
        {
            ans.push_back(s);
            return;
        }

        if (open < n)
        {
            generateParenthesis(n, open + 1, close, s + "(", ans);
        }
        if (close < n and close < open)
        {
            generateParenthesis(n, open, close + 1, s + ")", ans);
        }
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        generateParenthesis(n, 0, 0, "", ans);
        return ans;
    }
};

int main()
{
    int n = 3;
    Solution s;
    vector<string> result = s.generateParenthesis(n);
    for (int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}