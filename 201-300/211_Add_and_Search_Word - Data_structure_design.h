#include <string>
#include <memory.h>
using namespace std;

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() { root = new TrieNode(); }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* node = root;
        for(char& c : word){
            if(node->next[c - 'a'] == nullptr)
                node->next[c - 'a'] = new TrieNode();
            node = node->next[c - 'a'];
        }
        node->isword = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(root, word, 0);
    }

private:
    class TrieNode{
    public:
        bool isword;
        TrieNode* next[26];
        TrieNode() : isword(false){ memset(next, 0, 26 * sizeof(TrieNode*)); }
    };

    TrieNode* root;

    bool search(TrieNode* root, string& s, int index){
        while(index < s.length() && s[index] != '.'){
            if(root->next[s[index] - 'a'] == nullptr)
                return false;
            root = root->next[s[index++] - 'a'];
        }

        if(index == s.length())
            return root->isword;
        
        for(int c = 0; c < 26; c++){
            if(root->next[c] != nullptr && search(root->next[c], s, index + 1))
                return true;
        }
        return false;
    }
};