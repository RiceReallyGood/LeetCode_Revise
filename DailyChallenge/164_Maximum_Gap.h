#include <vector>
using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        int N = nums.size();
        int minele = nums[0], maxele = nums[0];
        for(int i = 0; i < N; i++){
            minele = min(minele, nums[i]);
            maxele = max(maxele, nums[i]);
        }
        if(maxele == minele) return 0;

        int bucketsize = (maxele - minele - 1) / (N - 1) + 1;
        int bucketnum = (N - 1) / bucketsize + 1;

        vector<pair<int, int>> buckets(bucketnum, pair<int, int>(-1, -1));

        for(int i = 0; i < N; i++){
            auto& bucket = buckets[(nums[i] - minele) / bucketsize];

            if(bucket.first == -1){
                bucket.first = bucket.second = nums[i];
            }
            else{
                bucket.first = min(bucket.first, nums[i]);
                bucket.second = max(bucket.second, nums[i]);
            }
        }

        int prev = buckets[0].second;
        int res = 0;
        for(int i = 1; i < bucketnum; i++){
            if(buckets[i].first == -1)
                continue;
            
            res = max(res, buckets[i].first - prev);
            prev = buckets[i].second;
        }
        return res;
    }
};

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        int N = nums.size();
        int minele = nums[0], maxele = nums[0];
        for(int i = 0; i < N; i++){
            minele = min(minele, nums[i]);
            maxele = max(maxele, nums[i]);
        }
        if(maxele == minele) return 0;

        int bucketsize = (maxele - minele) / N + 1;

        vector<pair<int, int>> buckets(N, pair<int, int>(-1, -1));

        for(int i = 0; i < N; i++){
            auto& bucket = buckets[(nums[i] - minele) / bucketsize];

            if(bucket.first == -1){
                bucket.first = bucket.second = nums[i];
            }
            else{
                bucket.first = min(bucket.first, nums[i]);
                bucket.second = max(bucket.second, nums[i]);
            }
        }

        int prev = buckets[0].second;
        int res = 0;
        for(int i = 1; i < N; i++){
            if(buckets[i].first == -1)
                continue;
            
            res = max(res, buckets[i].first - prev);
            prev = buckets[i].second;
        }
        return res;
    }
};