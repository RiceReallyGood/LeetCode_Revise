#include <string>
using namespace std;

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() { root = new TrieNode(); }
    ~Trie(){ destroy(root); }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* node = root;
        for(char& c : word){
            if((node->next)[c - 'a'] == nullptr)
                (node->next)[c - 'a'] = new TrieNode();
            node = (node->next)[c - 'a'];
        }
        node->isword = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* node = root;
        for(char& c : word){
            if((node->next)[c - 'a'] == nullptr)
                return false;
            node = (node->next)[c - 'a'];
        }
        return node->isword;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(char& c : prefix){
            if((node->next)[c - 'a'] == nullptr)
                return false;
            node = (node->next)[c - 'a'];
        }
        return true;
    }

private:
    class TrieNode{
    public:
        bool isword;
        TrieNode* next[26];
        TrieNode() : isword(false){
            for(int i = 0; i < 26; i++)
                next[i] = nullptr;
        }
    };

    void destroy(TrieNode* root){
        if(root == nullptr) return;
        for(int i = 0; i < 26; i++)
            destroy((root->next)[i]);
        delete root;
    }

    TrieNode* root;
};