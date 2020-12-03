#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ret(k, 0);
        int sz1 = nums1.size(), sz2 = nums2.size();
        for(int i = max(0, k - sz2); i <= min(sz1, k); i++){
            vector<int> temp = Merge(maxNumber(nums1, i), maxNumber(nums2, k - i));
            if(larger(temp, 0, ret, 0))
                ret = temp;
        }
        return ret;
    }

private:
    vector<int> maxNumber(const vector<int>& nums, int k){
        int delnum = nums.size() - k;
        vector<int> ret;
        for(int i = 0; i < nums.size(); i++){
            while(delnum > 0 && !ret.empty() && nums[i] > ret.back()){
                ret.pop_back();
                delnum--;
            }
            ret.push_back(nums[i]);
        }

        while(ret.size() > k)
            ret.pop_back();
        return ret;
    }

    vector<int> Merge(const vector<int>& nums1, const vector<int>& nums2){
        int i1 = 0, i2 = 0;
        vector<int> ret;
        while(i1 < nums1.size() || i2 < nums2.size()){
            if(larger(nums1, i1, nums2, i2)){
                ret.push_back(nums1[i1++]);
            }
            else{
                ret.push_back(nums2[i2++]);
            }
        }
        return ret;
    }

    bool larger(const vector<int>& nums1, int i1, const vector<int>& nums2, int i2){
        while(i1 < nums1.size() && i2 < nums2.size()){
            if(nums1[i1] < nums2[i2]) return false;
            else if(nums1[i1] > nums2[i2]) return true;
            i1++, i2++;
        }
        return i2 == nums2.size();
    }
};