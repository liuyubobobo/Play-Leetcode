/// Source : https://leetcode.com/problems/generate-random-point-in-a-circle/description/
/// Author : liuyubobobo
/// Time   : 2018-08-28

#include <iostream>
#include <cmath>

using namespace std;


/// Using Mathematics and Polar Coorinates
/// About Inverse Transform Sampling in this problem, please follow these links
///
/// https://leetcode.com/problems/generate-random-point-in-a-circle/solution/
/// https://stackoverflow.com/questions/5837572/generate-a-random-point-within-a-circle-uniformly/50746409#50746409
///
/// Time Complexity: O(1)
/// Space Complexity: O(1)
class Solution {

private:
    double x, y, r;

public:
    Solution(double radius, double x_center, double y_center):
            x(x_center), y(y_center), r(radius){}

    vector<double> randPoint() {

        double randR = sqrt(randDouble(0.0, 1.0)) * r; // CDF
        double randAngle = randDouble(0.0, 2.0 * M_PI);
        return {x + randR * cos(randAngle), y + randR * sin(randAngle)};
    }

private:
    double randDouble(double minDouble, double maxDouble){

        double randNum = (double)rand() / INT_MAX;
        return randNum * (maxDouble - minDouble) + minDouble;
    }
};


int main() {

    return 0;
}