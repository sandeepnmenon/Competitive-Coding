#include<bits/stdc++.h>
using namespace std;

class Trie {
private:
    Trie* edges[26] = {};
    bool isWordEnd = false;
public:
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
            if(!traverse->edges[ch])
            {
                traverse->edges[ch] = new Trie();
            }
            traverse = traverse->edges[ch];
        }
        traverse->isWordEnd = true;
    }
    
    bool search(string word) {
        Trie* traverse = this;
        int len = word.length();
        for(int i=0; i < len; ++i)
        {
            int ch = word[i] - 'a';
            if(!traverse->edges[ch])
            {
                return false;
            }
            else
            {
                traverse = traverse->edges[ch];
            }
        }

        return traverse->isWordEnd;
    }
    
    bool startsWith(string prefix) {
        Trie* traverse = this;
        int len = prefix.length();
        for(int i=0; i < len; ++i)
        {
            int ch = prefix[i] - 'a';
            if(!traverse->edges[ch])
            {
                return false;
            }
            else
            {
                traverse = traverse->edges[ch];
            }
        }

        return true;
    }
};

int main()
{
    // Incomplete driver code
    vector<string> words = {"apple", "app"};
    Trie* obj = new Trie();
    for(string word: words)
        obj->insert(word);
    
    cout<<obj->search("apple");
    cout<<obj->startsWith("appl");

    return 0;
}