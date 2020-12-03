#include <vector>
using namespace std;

class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> in(n, 0), out(n, 0);
        for(int i = 0; i < requests.size(); i++){
            out[requests[i][0]]++;
            in[requests[i][0]]++;
        }

        bool isloop = true;
        for(int i = 0; i < n; i++){
            if(in[i] != out[i]){
                isloop = false;
                break;
            }
        }
        if(isloop) return requests.size();


        vector<vector<int>> req;
        int comeback = 0;
        for(int i = 0; i < requests.size(); i++){
            if(in[requests[i][0]] == 0 || out[requests[i][1]] == 0)
                continue;
            if(requests[i][0] == requests[i][1])
                comeback++;
            else
                req.push_back(requests[i]);
        }

        int m = req.size();
        int res = 0;
        for(int state = 0; state < (1 << m); state++){
            vector<int> income(n, 0);
            int count = 0;

            for(int j = 0; j < m; j++){
                if(state & (1 << j)){
                    income[req[j][0]]--;
                    income[req[j][1]]++;
                    count++;
                }
            }

            bool flag = true;
            for(int i = 0; i < n; i++){
                if(income[i] != 0){
                    flag = false;
                    break;
                }
            }
            if(flag) res = max(res, count);
        }
        return res + comeback;
    }
};