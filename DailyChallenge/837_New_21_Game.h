#include <vector>
using namespace std;

class Solution {
public:
    double new21Game(int N, int K, int W) {
        if(K + W - 1 <= N) return 1.;
        double p = 1./ double(W);
        vector<double> dp(N + 1);
        dp[0] = 1.;
        for(int it = 0; it < K; it++){
            double sum = 0.;
            for(int i = K - 1; i >= it && N - i < W; i--)
                sum += dp[i];
            for(int i = N; i >= K; i--){
                if(i - W >= it) sum += dp[i - W];
                dp[i] += p * sum;
            }

            double residue = 0.;
            for(int i = K - 1; i >= it; i--){
                sum -= dp[i];
                if(i - W >= it) sum += dp[i - W];
                dp[i] = p * sum;
                residue += dp[i];
            }
            if(residue <= 1e-5)
                break;
        }

        double ret = 0.;
        for(int i = K; i <= N; i++) ret += dp[i];
        return ret;
    }
};

class Solution {
public:
    double new21Game(int N, int K, int W) {
        double p = 1. / W;
        vector<double> dp(K + W);
        for(int i = K; i < K + W && i <= N; i++)
            dp[i] = 1.;
        double sum = 0.;
        for(int i = K; i < K + W; i++)
            sum += dp[i];
        
        for(int i = K - 1; i >= 0; i--){
            dp[i] = sum * p;
            sum = sum + dp[i] - dp[i + W];
        }
        return dp[0];
    }
};