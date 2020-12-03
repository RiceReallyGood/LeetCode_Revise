#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_multiset<int> elements1(nums1.begin(), nums1.end());
        vector<int> ret;
        for(int num : nums2){
            auto it = elements1.find(num);
            if(it != elements1.end()){
                ret.push_back(num);
                elements1.erase(it);
            }
        }
        return ret;
    }
};