#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tailele;
        for(int num : nums){
            auto it = lower_bound(tailele.begin(), tailele.end(), num);
            if(it == tailele.end()) tailele.push_back(num);
            else *it = num;
        }
        return tailele.size();
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tailele;
        for(int num : nums){
            int l = 0, r = tailele.size();
            while(l < r){
                int c = l + (r - l) / 2;
                if(tailele[c] < num) l = c + 1;
                else r = c;
            }
            if(l == tailele.size()) tailele.push_back(num);
            else tailele[l] = num;
        }
        return tailele.size();
    }
};