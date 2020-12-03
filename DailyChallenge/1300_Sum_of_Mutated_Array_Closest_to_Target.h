#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int sz = arr.size();
        vector<int> partialsum(sz + 1);
        sort(arr.begin(), arr.end());
        for(int i = 0; i < sz; i++)
            partialsum[i + 1] = partialsum[i] + arr[i];
        
        //upper bound
        int lvalue = min(target / sz, arr[0]), rvalue = arr.back() + 1;
        while(lvalue < rvalue){
            int cvalue = lvalue + (rvalue - lvalue) / 2;
            int index = upper_bound(arr.begin(), arr.end(), cvalue) - arr.begin();
            int adjustedsum = partialsum[index] + (sz - index) * cvalue;
            if(adjustedsum < target)
                lvalue = cvalue + 1;
            else
                rvalue = cvalue;
        }

        //chose lvalue or lvalue - 1
        int index1 = upper_bound(arr.begin(), arr.end(), lvalue - 1) - arr.begin();
        int sum1 = partialsum[index1] + (sz - index1) * (lvalue - 1);

        int index2 = upper_bound(arr.begin(), arr.end(), lvalue) - arr.begin();
        int sum2 = partialsum[index2] + (sz - index2) * lvalue;

        if((target - sum1) <= (sum2 - target))
            return lvalue - 1;
        else
            return lvalue;
    }
};

class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int sz = arr.size();
        int l = target / sz, r = *max_element(arr.begin(), arr.end());
        if(l > r) l = r;

        while(l < r){
            int c = l  + (r - l) / 2;
            if(adjustedsum(arr, c) < target)
                l = c + 1;
            else
                r = c;
        }
        int sum1 = adjustedsum(arr, l - 1);
        int sum2 = adjustedsum(arr, l);
        if(sum2 - target > target - sum1)
            return l - 1;
        else
            return l;
    }

private:
    int adjustedsum(vector<int>& nums, int value){
        int sum = 0;
        for(int num : nums){
            sum += num < value ? num : value;
        }
        return sum;
    }
};