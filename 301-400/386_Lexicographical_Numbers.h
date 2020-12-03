#include <vector>
using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        this->n = n;
        vector<int> res;
        for(int i = 1; i < 10 && i <= n; i++)
            AddPrefix(res, i);
        return res;
    }

private:
    int n;
    void AddPrefix(vector<int>& res, int prefix){
        res.push_back(prefix);

        for(int i = 0; i < 10; i++){
            if(prefix * 10 + i > n) break;
            AddPrefix(res, prefix * 10 + i);
        }
    }
};