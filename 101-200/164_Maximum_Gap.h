#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return 0;
        int minnum = *min_element(nums.begin(), nums.end());
        int maxnum = *max_element(nums.begin(), nums.end());
        if(minnum == maxnum) return 0;
        int bucketsize = (maxnum - minnum) / n + 1;
        vector<pair<int,int>> buckets(n, make_pair(1, 0));

        for(int num : nums){
            int id = (num - minnum) / bucketsize;
            if(buckets[id].first > buckets[id].second)
                buckets[id] = make_pair(num, num);
            else{
                buckets[id].first = min(buckets[id].first, num);
                buckets[id].second = max(buckets[id].second, num);
            }
        }

        int maxgap = 0;
        int previd = -1;
        for(int i = 0; i < n; i++){
            if(buckets[i].first > buckets[i].second) continue;
            if(previd != -1)
                maxgap = max(maxgap, buckets[i].first - buckets[previd].second);
            previd = i;
        }
        return maxgap;
    }
};

/* 
maxgap >= ceil((maxnum - minnum) / (n - 1)) >=  (maxnum - minnum) / (n - 1)
       > (maxnum - minnum) / n >= floor((maxnum - minnum) / n)

thus maxgap > floor((maxnum - minnum) / n)
so bucket size can be (maxnum - minnum) / n + 1
*/