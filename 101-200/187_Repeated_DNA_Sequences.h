#include <string>
#include <vector>
#include <bitset>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.length() < 10) return {};
        int num[128] = {0};
        num['A'] = 0b00, num['C'] = 0b01, num['G'] = 0b10, num['T'] = 0b11;
        int index = 0;
        int seq  = 0, mask = (1 << 20) - 1;
        bitset<1 << 20> once, twice;
        while(index < 9) seq = (seq << 2) | num[s[index++]];

        vector<string> ret;
        while(index < s.length()){
            seq = ((seq << 2) | num[s[index++]]) & mask;
            if(twice.test(seq)) continue;
            if(once.test(seq)){
                ret.push_back(s.substr(index - 10, 10));
                twice.set(seq);
            }
            else
                once.set(seq);
        }
        return ret;
    }
};