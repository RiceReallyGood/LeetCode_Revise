#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.empty()) return {};
        vector<string> ret;
        int i = 0, j = 1;
        while(i < nums.size()){
            while(j < nums.size() && nums[j] == nums[j - 1] + 1) j++;
            if(j == i + 1){
                ret.emplace_back(to_string(nums[i]));
            }
            else{
                string s = to_string(nums[i]);
                s += "->";
                s += to_string(nums[j - 1]);
                ret.emplace_back(s);
            }
            i = j;
            j++;
        }
        return ret;
    }
};