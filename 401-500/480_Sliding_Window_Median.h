#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> window(nums.begin(), nums.begin() + k);
        auto mid = next(window.begin(), k / 2);
        int n = nums.size();
        vector<double> res;

        for(int i = k; ; i++){
            if(k & 1)
                res.push_back(*mid);
            else
                res.push_back((double(*mid) + double(*(prev(mid)))) * 0.5);
            if(i == n) break;

            window.insert(nums[i]);
            if(nums[i] < *mid) mid = prev(mid);

            if(nums[i - k] <= *mid) mid = next(mid);
            window.erase(window.find(nums[i - k]));
        }

        return res;
    }
};

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<int> window(nums.begin(), nums.begin() + k);
        sort(window.begin(), window.end());
        vector<double> res;
        const int mid = k / 2;

        for(int i = k; ; i++){
            if(k & 1) res.push_back(window[mid]);
            else res.push_back((double(window[mid]) + double(window[mid - 1])) * 0.5);
            if(i == nums.size()) break;

            int ipos = lower_bound(window.begin(), window.end(), nums[i]) - window.begin();
            int opos = lower_bound(window.begin(), window.end(), nums[i - k]) - window.begin();

            if(ipos <= opos){
                for(int j = opos; j > ipos; j--)
                    window[j] = window[j - 1];
                window[ipos] = nums[i];
            }
            else{
                for(int j = opos; j < ipos - 1; j++)
                    window[j] = window[j + 1];
                window[ipos - 1] = nums[i];
            }
        }

        return res;
    }
};

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        unordered_map<int, int> dels;
        priority_queue<int, vector<int>, greater<int>> pq1(nums.begin(), nums.begin() + k);
        priority_queue<int, vector<int>, less<int>> pq2;
        vector<double> res;

        for(int i = 0; i < k / 2; i++){
            pq2.push(pq1.top());
            pq1.pop();
        }

        for(int i = k; ; i++){
            if(k & 1) res.push_back(pq1.top());
            else res.push_back(0.5 * (double(pq1.top()) + double(pq2.top())));

            if(i == nums.size()) break;

            dels[nums[i - k]]++;
            if(nums[i - k] >= pq1.top()){
                if(pq2.empty() || nums[i] >= pq2.top()){
                    pq1.push(nums[i]);
                }
                else{
                    pq2.push(nums[i]);

                    //rebalance
                    pq1.push(pq2.top());
                    pq2.pop();
                }
            }
            else{
                if(nums[i] <= pq1.top()){
                    pq2.push(nums[i]);
                }
                else{
                    pq1.push(nums[i]);

                    //rebalance
                    pq2.push(pq1.top());
                    pq1.pop();
                }
            }

            while(dels[pq1.top()]){
                dels[pq1.top()]--;
                pq1.pop();
            }
            while(!pq2.empty() && dels[pq2.top()]){
                dels[pq2.top()]--;
                pq2.pop();
            }
        }
        return res;
    }
};