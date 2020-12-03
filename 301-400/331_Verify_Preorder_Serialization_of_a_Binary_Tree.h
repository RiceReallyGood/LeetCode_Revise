#include <string>
using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        int b = 0;
        if(!dfs(preorder, b) || b != preorder.length())
            return false;
        return true;
    }

private:
    bool dfs(string& preorder, int& b){
        if(b >= preorder.length()) return false;

        while(b < preorder.length() && preorder[b] != ',') b++;
        if(preorder[b - 1] == '#') return true;

        b++;
        if(!dfs(preorder, b)) return false;
        b++;
        if(!dfs(preorder, b)) return false;
        return true;
    }
};