#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> hash;
        for (int x : nums)
        {
            hash[x]++;
        }
        vector<vector<int>> kfreq(nums.size() + 1);
        unordered_map<int, int>::iterator it = hash.begin();
        while (it != hash.end())
        {
            kfreq[it->second].push_back(it->first);
            ++it;
        }

        int n = kfreq.size();
        vector<int> ans;
        for (int i = n - 1; i >= 0 and ans.size() < k; --i)
        {
            if (kfreq[i].size() != 0)
            {
                for (int num : kfreq[i])
                {
                    ans.push_back(num);
                    if (ans.size() == k)
                        break;
                }
            }
        }

        return ans;
    }
};

class Solution_2
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        int hash[20004] = {0};
        for (int x : nums)
        {
            if (x < 0)
            {
                hash[10000 - x]++;
            }
            else
            {
                hash[x]++;
            }
        }
        vector<vector<int>> kfreq(nums.size() + 1);
        for (int i = 0; i < 20004; ++i)
        {
            if (hash[i] > 0)
            {
                if (i >= 10000)
                {

                    kfreq[hash[i]].push_back(10000 - i);
                }
                else
                {
                    kfreq[hash[i]].push_back(i);
                }
            }
        }
        int n = kfreq.size();
        vector<int> ans;
        for (int i = n - 1; i >= 0 and ans.size() < k; --i)
        {
            if (kfreq[i].size() != 0)
            {
                for (int num : kfreq[i])
                {
                    ans.push_back(num);
                    if (ans.size() == k)
                        break;
                }
            }
        }

        return ans;
    }
};

int main()
{
    // vector<int> nums = {-1, -1, -1, 2, 2, 3, 3, 3, 3, 3};
    vector<int> nums = {1, 2};
    int k = 2;
    Solution s;
    vector<int> ans = s.topKFrequent(nums, k);
    for (int x : ans)
    {
        cout << x << " ";
    }
    cout << endl;
}