#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> eles1(nums1.begin(), nums1.end());
        vector<int> andset;
        for(int num : nums2){
            if(eles1.find(num) != eles1.end()){
                andset.push_back(num);
                eles1.erase(num);
            }
        }
        return andset;
    }
};