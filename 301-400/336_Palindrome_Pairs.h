#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

//Tire
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        Trie t;
        for(int i = 0; i < words.size(); i++){
            t.insert(words[i], i);
        }

        vector<vector<int>> ret;
        for(int i = 0; i < words.size(); i++){
            int n = words[i].length();
            string rev = words[i];
            reverse(rev.begin(), rev.end());
            int j = t.search(rev);
            if(j != -1 && j != i) ret.push_back({i, j});
            vector<int> prefix1 = KMP(words[i]);
            vector<int> prefix2 = KMP(rev);

            int len = 0;
            for(int k = 0; k < n; k++){
                if(len != 0 && rev[len] != words[i][k])
                    len = prefix2[len - 1];
                if(rev[len] == words[i][k]) len++;
            }

            while(len > 0){
                j = t.search(rev.substr(len));
                if(j != -1) ret.push_back({i, j});
                len = prefix2[len - 1];
            }

            len = 0;
            for(int k = 0; k < n; k++){
                if(len != 0 && words[i][len] != rev[k])
                    len = prefix1[len - 1];
                if(words[i][len] == rev[k]) len++;
            }

            while(len > 0){
                j = t.search(rev.substr(0, n - len));
                if(j != -1) ret.push_back({j, i});
                len = prefix1[len - 1];
            }
        }
        return ret;
    }

private:
    class Trie {
    public:
        /** Initialize your data structure here. */
        Trie() { root = new TrieNode(); }
        ~Trie(){ destroy(root); }
        
        /** Inserts a word into the trie. */
        void insert(string word, int index) {
            TrieNode* node = root;
            for(char& c : word){
                if((node->next)[c - 'a'] == nullptr)
                    (node->next)[c - 'a'] = new TrieNode();
                node = (node->next)[c - 'a'];
            }
            node->index = index;
        }
        
        /** Returns if the word is in the trie. */
        int search(string word) {
            TrieNode* node = root;
            for(char& c : word){
                if((node->next)[c - 'a'] == nullptr)
                    return -1;
                node = (node->next)[c - 'a'];
            }
            return node->index;
        }

    private:
        class TrieNode{
        public:
            int index;
            TrieNode* next[26];
            TrieNode() : index(-1){
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

    vector<int> KMP(const string& s){
        int len = s.length();
        vector<int> ret(len, 0);
        for(int i = 1, j = 0; i < len; i++){
            while(j != 0 && s[i] != s[j])
                j = ret[j - 1];
            if(s[i] == s[j])
                j++;
            ret[i] = j;
        }
        return ret;
    }
};


//Hashmap
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> str_index;
        for(int i = 0; i < words.size(); i++){
            str_index[words[i]] = i;
        }

        vector<vector<int>> ret;
        for(int i = 0; i < words.size(); i++){
            int n = words[i].length();
            string rev = words[i];
            reverse(rev.begin(), rev.end());
            if(rev != words[i] && str_index.find(rev) != str_index.end())
                ret.push_back({i, str_index[rev]});
            vector<int> prefix1 = KMP(words[i]);
            vector<int> prefix2 = KMP(rev);

            int len = 0;
            for(int k = 0; k < n; k++){
                if(len != 0 && rev[len] != words[i][k])
                    len = prefix2[len - 1];
                if(rev[len] == words[i][k]) len++;
            }

            while(len > 0){
                string right = rev.substr(len);
                if(str_index.find(right) != str_index.end())
                    ret.push_back({i, str_index[right]});
                len = prefix2[len - 1];
            }

            len = 0;
            for(int k = 0; k < n; k++){
                if(len != 0 && words[i][len] != rev[k])
                    len = prefix1[len - 1];
                if(words[i][len] == rev[k]) len++;
            }

            while(len > 0){
                string left = rev.substr(0, n - len);
                if(str_index.find(left) != str_index.end())
                    ret.push_back({str_index[left], i});
                len = prefix1[len - 1];
            }
        }
        return ret;
    }

private:
    vector<int> KMP(const string& s){
        int len = s.length();
        vector<int> ret(len, 0);
        for(int i = 1, j = 0; i < len; i++){
            while(j != 0 && s[i] != s[j])
                j = ret[j - 1];
            if(s[i] == s[j])
                j++;
            ret[i] = j;
        }
        return ret;
    }
};