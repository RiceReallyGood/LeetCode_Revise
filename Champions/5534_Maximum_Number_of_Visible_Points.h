#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        static double pi = 3.14159265358979;
        int posx = location[0], posy = location[1];
        for(int i = 0; i < points.size(); i++){
            points[i][0] -= posx;
            points[i][1] -= posy;
        }

        int sameposition = 0;
        vector<double> args;
        for(int i = 0; i < points.size(); i++){
            if(points[i][0] == 0 && points[i][1] == 0){
                sameposition++;
                continue;
            }

            if(points[i][0] == 0){
                if(points[i][1] > 0)
                    args.push_back(90);
                else
                    args.push_back(270);
            }
            else if(points[i][1] == 0){
                if(points[i][0] > 0)
                    args.push_back(0);
                else
                    args.push_back(180);
            }
            else{
                if(points[i][0] > 0 && points[i][1] > 0)
                    args.push_back(std::atan(points[i][1] / points[i][0]) / pi * 180);
                else if(points[i][0] > 0 && points[i][1] < 0)
                    args.push_back(std::atan(points[i][1] / points[i][0]) / pi * 180 + 360);
                else
                    args.push_back(std::atan(points[i][1] / points[i][0]) / pi * 180 + 180);
            }
        }


        sort(args.begin(), args.end());
        int len = 0;
        int n = args.size();
        for(int i = 0, j = 0; i < n; i++){
            while(mymod(args[j] - args[i]) <= angle){
                j = (j + 1) % n;
                if(j == i) return n;
            }

            len = max(len , (j - i + n) % n);
        }

        return len + sameposition;
    }

private:
    double mymod(double theta){
        return theta < 0 ? theta + 360 : theta;
    }
};