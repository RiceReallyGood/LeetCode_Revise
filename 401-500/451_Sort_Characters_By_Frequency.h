#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        int count[128] {0};
        for(char c : s) count[c]++;

        vector<pair<int,char>> freq;
        for(int c = 0; c < 128; c++){
            if(count[c] > 0){
                freq.push_back(make_pair(count[c], c));
            }
        }

        sort(freq.begin(), freq.end(), std::greater<pair<int,char>>());

        string ret;
        for(int i = 0; i < freq.size(); i++){
            for(int j = 0; j < freq[i].first; j++)
                ret.push_back(freq[i].second);
        }
        return ret;
    }
};