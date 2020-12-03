#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.length() > s.length()) return {};
        int counts[26] {0};
        for(char c : p) counts[c - 'a']++;
        int diff = p.length();
        for(int i = 0; i < p.length(); i++){
            counts[s[i] - 'a']--;
            if(counts[s[i] -'a'] >= 0) diff--;
            else diff++;
        }

        vector<int> ret;
        if(diff == 0) ret.push_back(0);

        for(int i = p.length(); i < s.length(); i++){
            int j = i - p.length();
            counts[s[i] - 'a']--;
            if(counts[s[i] -'a'] >= 0) diff--;
            else diff++;

            counts[s[j] - 'a']++;
            if(counts[s[j] -'a'] > 0) diff++;
            else diff--;

            if(diff == 0) ret.push_back(j + 1);
        }
        return ret;
    }
};