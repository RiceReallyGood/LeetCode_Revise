#include <vector>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.empty()) return 0;
        int count = 1, leftbound = 0;
        int prevcount = 1, leftboundcount = 1;
        for(int i = 1; i < ratings.size(); i++){
            if(ratings[i - 1] < ratings[i]){
                leftbound = i;
                leftboundcount = ++prevcount;
                count += prevcount;
            }
            else if(ratings[i - 1] == ratings[i]){
                leftbound = i;
                leftboundcount = prevcount = 1;
                count += prevcount;
            }
            else{
                prevcount = 1;
                count += i - leftbound;
                if(leftboundcount == i - leftbound){
                    leftboundcount++;
                    count++;
                }
            }
        }
        return count;
    }
};

class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.empty()) return 0;
        int n = ratings.size();
        vector<int> candies(n, 1);
        for(int i = 1; i < n; i++){
            if(ratings[i - 1] < ratings[i])
                candies[i] = candies[i - 1] + 1;
        }

        for(int i = n - 2; i >= 0; i--){
            if(ratings[i] > ratings[i + 1])
                candies[i] = max(candies[i], candies[i + 1] + 1);
        }
        int sum = 0;
        for(int i = 0; i < n; i++)
            sum += candies[i];
        return sum;
    }
};