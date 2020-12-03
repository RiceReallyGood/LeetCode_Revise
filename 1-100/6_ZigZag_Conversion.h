#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        int cycle = 2 * numRows - 2;
        string ret;
        //第一行
        for(int i = 0; i < s.length(); i += cycle)
            ret.push_back(s[i]);
        
        //中间的行
        for(int row = 1; row < numRows - 1; row++){
            int shift = (numRows - 1 - row) * 2;
            for(int i = row; i < s.length(); i += cycle){
                ret.push_back(s[i]);
                if(i + shift < s.length())
                    ret.push_back(s[i + shift]);
            }
        }

        //之后一行
        for(int i = numRows - 1; i < s.length(); i += cycle)
            ret.push_back(s[i]);
        
        return ret;
    }
};