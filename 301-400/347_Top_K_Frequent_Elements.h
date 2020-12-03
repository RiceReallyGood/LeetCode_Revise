#include <vector>
#include <unordered_map>
#include <random>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int num : nums)
            ++freq[num];
        
        vector<pair<int, int>> freq_num;
        for(auto it = freq.begin(); it != freq.end(); it++){
            freq_num.push_back(make_pair(it->second, it->first));
        }

        srand(time(NULL));
        partition_3way(freq_num, 0, freq_num.size() - 1, k - 1);

        vector<int> ret;
        for(int i = 0; i < k; i++){
            ret.push_back(freq_num[i].second);
        }
        return ret;
    }

private:
    void partition_3way(vector<pair<int, int>>& freq_num, int l, int r, int k){
        swap(freq_num[l], freq_num[rand() % (r - l + 1) + l]);
        int v = freq_num[l].first;

        int gt = l, lt = r + 1;
        int i = l + 1;
        while(i < lt){
            if(freq_num[i].first > v)
                swap(freq_num[++gt], freq_num[i++]);
            else if(freq_num[i].first < v)
                swap(freq_num[--lt], freq_num[i]);
            else
                ++i;
        }

        swap(freq_num[l], freq_num[gt]);

        if(k < gt)
            partition_3way(freq_num, l, gt - 1, k);
        else if(k >= lt)
            partition_3way(freq_num, lt, r, k);
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int num : nums)
            ++freq[num];

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;

        for(auto it = freq.begin(); it != freq.end(); it++){
            pq.push(make_pair(it->second, it->first));
            if(pq.size() > k) pq.pop();
        }

        vector<int> ret;

        while(!pq.empty()){
            ret.push_back(pq.top().second);
            pq.pop();
        }
        return ret;
    }
};