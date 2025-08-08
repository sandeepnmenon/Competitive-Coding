#include<bits/stdc++.h>
using namespace std;

class WordDictionary {
private:
    WordDictionary* edges[26] = {};
    bool isWordEnd;
public:
    WordDictionary() {
        isWordEnd = false;
    }
    
    void addWord(string word) {
        WordDictionary* traverse = this;
        for(char ch: word)
        {
            ch-='a';
            if(!traverse->edges[ch])
            {
                traverse->edges[ch] = new WordDictionary();
            }
            traverse = traverse->edges[ch];
        }
        traverse->isWordEnd = true;
    }
    
    bool search(string word) {
        WordDictionary* traverse = this;
        return search(word, this);
    }

    bool search(string word, WordDictionary* root) {
        int len = word.length();

        for(int i=0; i < len; ++i)
        {
            int ch = word[i] - 'a';
            if(word[i]!='.')
            {
                if(!root->edges[ch])
                    return false;
                root = root->edges[ch];
            }
            else
            {
                bool word_found = false;
                for(int j = 0; j < 26 ; ++j)
                {
                    if(root->edges[j])
                        word_found = word_found or search(word.substr(i+1), root->edges[j]);
                    if(word_found)
                        return true;
                }
                return false;
            }
        }

        return root->isWordEnd;
    }
};


int main()
{
    // Incomplete driver code
    vector<string> words = {"apple", "app"};
    WordDictionary* obj = new WordDictionary();
    for(string word: words)
        obj->addWord(word);
    
    cout<<obj->search("apple");
    cout<<obj->search(".pple");

    return 0;
}