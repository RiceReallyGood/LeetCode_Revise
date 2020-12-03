#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int half = (n + m) / 2;

        //Binary Search
        int l = max(0, half - m), r = min(n, half);
        while(l < r){
            int c1 = l + (r - l) / 2;
            int c2 = half - c1;
            if(nums1[c1] < nums2[c2 - 1])
                l = c1 + 1;
            else if(c1 > l && nums1[c1 - 1] > nums2[c2])
                r = c1 - 1;
            else{
                l = r = c1;
            }
        }

        if((n + m) % 2 == 0){
            int rightmin = INT_MAX;
            if(l < n) rightmin = min(rightmin, nums1[l]);
            if(half - l < m) rightmin = min(rightmin, nums2[half - l]);

            int leftmax = INT_MIN;
            if(l > 0) leftmax = max(leftmax, nums1[l - 1]);
            if(half - l > 0) leftmax = max(leftmax, nums2[half - l - 1]);

            return double(leftmax + rightmin) / 2.;
        }
        else{
            int rightmin = INT_MAX;
            if(l < n) rightmin = min(rightmin, nums1[l]);
            if(half - l < m) rightmin = min(rightmin, nums2[half - l]);
            return rightmin;
        }
    }
};