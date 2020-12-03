#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastindex(256, -1);
        int left = 0, right = 0;
        int maxlen = 0;
        while(right < s.length()){
            if(lastindex[s[right]] >= left){
                maxlen = max(maxlen, right - left);
                left = lastindex[s[right]] + 1;
            }
            lastindex[s[right]] = right;
            right++;
        }
        maxlen = max(maxlen, right - left);
        return maxlen;
    }
};