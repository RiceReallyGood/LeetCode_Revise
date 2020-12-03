#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        MaxIndexHeap counts(26);
        for(int i = 0, j = 0; j < s.length(); j++){
            counts.increase(s[j] - 'A', 1);
            while(counts.top() + k < j - i + 1)
                counts.increase(s[i++] -'A', -1);
            res = max(res, j - i + 1);
        }
        return res;
    }

private:
    class MaxIndexHeap{
    public:
        MaxIndexHeap(int sz): n(sz), data(sz, 0), indices(sz, 0), rev(sz, 0) {
            for(int i = 0; i < n; i++){
                indices[i] = i;
                rev[i] = i;
            }
        }

        int top() { return data[indices[0]]; }

        void increase(int index, int diff){
            data[index] += diff;
            int i = rev[index];
            shiftUp(i);
            shiftDown(i);
        }

    private:
        vector<int> data;
        vector<int> indices;
        vector<int> rev;

        int n;

        void shiftUp(int i){
            while(i > 0){
                int j = (i - 1) / 2;
                if(data[indices[j]] >= data[indices[i]])
                    break;
                
                std::swap(indices[i], indices[j]);
                rev[indices[i]] = i;
                i = j;
            }
            rev[indices[i]] = i;
        }

        void shiftDown(int i){
            int j;
            while((j = 2 * i + 1) < n){
                if(j < n - 1 && data[indices[j]] < data[indices[j + 1]])
                    j = j + 1;
                
                if(data[indices[i]] >= data[indices[j]])
                    break;
                
                std::swap(indices[i], indices[j]);
                rev[indices[i]] = i;
                i = j;
            }
            rev[indices[i]] = i;
        }
    };
};

class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        int counts[26] {0};
        int max_val = 0;
        for(int i = 0, j = 0; j < s.length(); j++){
            counts[s[j] -'A']++;
            max_val = max(max_val, counts[s[j] -'A']);
            if((j - i + 1) > max_val + k)
                counts[s[i++] -'A']--;
            res = max(res, j - i + 1);
        }
        return res;
    }
};