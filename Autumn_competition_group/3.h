#include <vector>
#include <queue>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> numsGame(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n);
        for(int i = 0; i < n; i++){
            arr[i] = nums[i] - nums[0] - i;
        }
        priority_queue<int, vector<int>,less<int>> pq1;
        priority_queue<int, vector<int>,greater<int>> pq2;

        pq2.push(arr[0]);
        vector<int> res(n);
        for(int i = 1; i < n; i++){
            if(i & 1){
                if(arr[i] <= pq2.top()){
                    pq1.push(arr[i]);
                    res[i] = (pq2.top() - arr[i] + res[i - 1]) % mod;
                }
                else{
                    int prev = pq2.top();
                    pq1.push(pq2.top());
                    pq2.pop();
                    pq2.push(arr[i]);
                    int curr = pq2.top();
                    res[i] = (arr[i] - prev + res[i - 1]) % mod;
                }
            }
            else{
                if(arr[i] >= pq1.top()){
                    int prev = pq2.top();
                    pq2.push(arr[i]);
                    int curr = pq2.top();
                    res[i] = (arr[i] - curr + res[i - 1]) % mod;
                }
                else{
                    int prev = pq2.top();
                    pq2.push(pq1.top());
                    pq1.pop();
                    pq1.push(arr[i]);
                    int curr = pq2.top();
                    res[i] = (curr - arr[i] + res[i - 1]) % mod;
                }
            }
        }
        return res;
    }

private:
    const static int mod = 1e9 + 7;
};