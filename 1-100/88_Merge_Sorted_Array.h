#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i = m + n - 1; i >= n; i--)
            nums1[i] = nums1[i - n];
        int i = n, j = 0, index = 0;
        while(i < m + n && j < n){
            if(nums1[i] <= nums2[j]) nums1[index++] = nums1[i++];
            else nums1[index++] = nums2[j++];
        }
        while(j < n) nums1[index++] = nums2[j++];
    }
};