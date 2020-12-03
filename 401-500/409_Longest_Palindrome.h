#include <string>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        int count[128] = {0};

        for(char c : s) count[c]++;

        bool odd = false;
        int len = 0;
        for(int i = 0; i < 128; i++){
            if(count[i] & 1){
                len += count[i] - 1;
                odd = true;
            }
            else
                len += count[i];
        }

        return odd ? len + 1 : len;
    }
};