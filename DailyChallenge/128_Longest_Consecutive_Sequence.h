#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numset(nums.begin(), nums.end());
        int maxlen = 0;
        for(int i = 0; i < nums.size(); i++){
            if(numset.find(nums[i]) != numset.end()){
                numset.erase(nums[i]);
                int count = 1;
                int temp = nums[i] - 1;
                while(numset.find(temp) != numset.end()){
                    numset.erase(temp);
                    count++;
                    temp--;
                }
                temp = nums[i] + 1;
                while(numset.find(temp) != numset.end()){
                    numset.erase(temp);
                    count++;
                    temp++;
                }
                maxlen = max(maxlen, count);
            }
        }
        return maxlen;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numset(nums.begin(), nums.end());
        int maxlen = 0;
        for(int num : nums){
            if(numset.find(num - 1) != numset.end()) continue;

            int count = 1;
            while(numset.find(num + 1) != numset.end()){
                num++;
                count++;
            }
            maxlen = max(maxlen, count);
        }
        return maxlen;
    }
};