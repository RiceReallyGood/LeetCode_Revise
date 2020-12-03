#include <vector>
#include <cstdlib>
#include <cmath>
using namespace std;

class Solution { //错误 概率不均匀
public:
    Solution(double radius, double x_center, double y_center) : x(x_center), y(y_center), r(radius) {}
    
    vector<double> randPoint() {
        double rho = r * rand() / RAND_MAX;
        double theta = 2. * 3.14159265358979 * rand() / RAND_MAX;
        return {x + rho * cos(theta), y + rho * sin(theta)};
    }

private:
    double x, y, r;
};

class Solution {
public:
    Solution(double radius, double x_center, double y_center) : x(x_center), y(y_center), r(radius) {}
    
    vector<double> randPoint() {
        double rho = r * sqrt(double(rand()) / double(RAND_MAX));
        double theta = 6.28318530717958 * rand() / RAND_MAX;
        return {x + rho * cos(theta), y + rho * sin(theta)};
    }

private:
    double x, y, r;
};