#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        int maxlen = 0;
        for(int i = 0; i < s.length(); i++){
            int count[26] = {0};
            for(int j = i; j < s.length(); j++){
                if(++count[s[j] - 'a'] < k) continue;
                int flag = true;
                for(int c = 0; c < 26; c++){
                    if(count[c] == 0) continue;
                    if(count[c] < k){
                        flag = false;
                        break;
                    }
                }
                if(flag) maxlen = max(maxlen, j - i + 1);
            }
        }
        return maxlen;
    }
};

class Solution {
public:
    int longestSubstring(string s, int k) {
        if(s.size() == 0 || s.size() < k) return 0;
        unordered_map<char,int> char_Num;
        for(char p : s) char_Num[p]++;
        vector<int> index;//切割点
        for(int i = 0; i < s.size(); i++){
            if(char_Num[s[i]] < k) index.push_back(i);
        }
        if(index.empty()) return s.size();
        int left = 0, len = 0, ans = 0;
        index.push_back(s.size());//来计算最后一段字符串的长度
        for(int i = 0; i < index.size(); i++){
            len = index[i] - left;
            if(len >= k && len > ans)
                ans = max(ans,longestSubstring(s.substr(left, len), k));
            left = index[i] + 1;
        }
        return ans;
    }
};