#include<bits/stdc++.h>
using namespace std;


class Trie {
private:
    Trie* edges[26] = {};
    bool isWordEnd = false;
public:
    string word;
    Trie() {
    }
    ~Trie()
    {
        for(int i=0;i<26;++i)
            delete this->edges[i];
    }
    void insert(string word) {
        Trie* traverse = this;
        int len = word.length();
        for(int i = 0; i < len; ++i)
        {
            int ch = word[i] - 'a';
            if(!traverse->isEdge(word[i]))
            {
                traverse->edges[ch] = new Trie();
            }
            traverse = traverse->edges[ch];
        }
        traverse->isWordEnd = true;
        traverse->word = word;
    }

    bool isEdge(char ch)
    {
        return this->edges[ch - 'a'] != NULL;
    }

    Trie* traverseEdge(char ch)
    {
        return this->edges[ch - 'a'];
    }

    bool isWordEnding()
    {
        return this->isWordEnd;
    }
};

class Solution {
public:
    void findInTrie(int i, int j, vector<vector<char>>& board, Trie* root, int m, int n, unordered_set<string> &ans)
    {
        if(root->isWordEnding())
        {
            ans.insert(root->word);
        }

        if(i<0 or j<0 or i==m or j==n)
            return;
        
        if(!root->isEdge(board[i][j]))
        {
            return;
        }

        root = root->traverseEdge(board[i][j]);

        findInTrie(i - 1, j, board, root, m, n, ans);
        findInTrie(i, j - 1, board, root, m, n, ans);
        findInTrie(i + 1, j, board, root, m, n, ans);
        findInTrie(i, j + 1, board, root, m, n, ans);
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* root = new Trie();
        for(string word: words)
        {
            root->insert(word);
        }
        int m = board.size(), n = board[0].size();
        vector<string> ans;
        unordered_set<string> temp_ans;
        for(int i = 0; i < m ; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                findInTrie(i, j, board, root, m, n, temp_ans);
            }
        }
        
        ans.insert(ans.end(), temp_ans.begin(), temp_ans.end());

        return ans;
    }
};


int main()
{
    vector<vector<char>> board = {{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
    vector<string> words = {"oath","pea","eat","rain"};
    Solution sol;
    vector<string> ans = sol.findWords(board, words);
    for(string str: ans)
    {
        cout<<str<<" ";
    }
    cout<<endl;

    return 0;
}