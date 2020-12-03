#include <vector>
#include <string>
#include <memory.h>
using namespace std;

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if(board.empty() || board[0].empty()) return {};
        int m = board.size(), n = board[0].size();
        root = new TrieNode();
        for(int i = 0; i < words.size(); i++){
            addWord(words[i]);
        }


        string path;
        vector<string> res;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                dfs(board, i, j, root, path, res);
            }
        }
        destory(root);
        return res;
    }

private:
    class TrieNode{
    public:
        TrieNode() : isword(false), childcount(0){
            memset(next, 0, 26 * sizeof(TrieNode*));
        }
        bool isword;
        int childcount;
        TrieNode* next[26];
    };

    TrieNode* root;

    void destory(TrieNode* root){
        if(root == nullptr) return;

        for(int i = 0; i < 26; i++){
            destory(root->next[i]);
        }

        delete root;
    }

    void addWord(string& word) {
        TrieNode* node = root;
        for(char& c : word){
            if(node->next[c - 'a'] == nullptr){
                node->childcount++;
                node->next[c - 'a'] = new TrieNode();
            }
            node = node->next[c - 'a'];
        }
        node->isword = true;
    }

    void dfs(vector<vector<char>>& board, int row, int col, TrieNode* node, string& path, vector<string>& res){
        char c = board[row][col];
        TrieNode* currnode = node->next[c - 'a'];
        if(currnode == nullptr) return;
        path.push_back(c);
        board[row][col] = '#';
        if(currnode->isword){
            res.push_back(path);
            currnode->isword = false;
        }
        if(row > 0 && board[row - 1][col] != '#')
            dfs(board, row - 1, col, currnode, path, res);
        if(row < board.size() - 1 && board[row + 1][col] != '#')
            dfs(board, row + 1, col, currnode, path, res);
        if(col > 0 && board[row][col - 1] != '#')
            dfs(board, row, col - 1, currnode, path, res);
        if(col < board[0].size() - 1 && board[row][col + 1] != '#')
            dfs(board, row, col + 1, currnode, path, res);
        
        if(currnode->childcount == 0){
            delete currnode;
            node->next[c - 'a'] = nullptr;
            node->childcount--;
        }
        board[row][col] = c;
        path.pop_back();
    }
};