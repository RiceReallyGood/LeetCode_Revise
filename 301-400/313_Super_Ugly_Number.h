#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int k = primes.size();
        vector<int> SUN = {1};

        vector<int> next = primes;
        vector<int> point(k, 0);


        while(SUN.size() < n){
            int minele = INT_MAX;
            for(int i = 0; i < k; i++)
                minele = min(minele, next[i]);
            SUN.push_back(minele);

            for(int i = 0; i < k; i++){
                if(next[i] == minele){
                    point[i]++;
                    next[i] = SUN[point[i]] * primes[i];
                }
            }
        }

        return SUN.back();
    }
};

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int k = primes.size();
        vector<int> SUN = {1};

        vector<int> next = primes;
        vector<int> point(k, 0);


        while(SUN.size() < n){
            int minele = INT_MAX, idx = -1;
            for(int i = 0; i < k; i++){
                if(next[i] < minele){
                    minele = next[i];
                    idx = i;
                }
                else if(next[i] == minele){
                    point[i]++;
                    next[i] = SUN[point[i]] * primes[i];
                }
            }
            SUN.push_back(minele);
            point[idx]++;
            next[idx] = SUN[point[idx]] * primes[idx];
        }

        return SUN.back();
    }
};