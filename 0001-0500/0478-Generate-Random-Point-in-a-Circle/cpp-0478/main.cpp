/// Source : https://leetcode.com/problems/generate-random-point-in-a-circle/description/
/// Author : liuyubobobo
/// Time   : 2018-08-28

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;


/// Rejection Sampling
/// Time Complexity: O(1)
/// Space Complexity: O(1)
class Solution {

private:
    double x, y, r;

public:
    Solution(double radius, double x_center, double y_center):
            x(x_center), y(y_center), r(radius){}

    vector<double> randPoint() {

        double randx, randy;
        do{
            randx = x - r + randDouble(0, 2 * r);
            randy = y - r + randDouble(0, 2 * r);
        }while(!inCircle(randx, randy));
        return {randx, randy};
    }

private:
    double randDouble(double minDouble, double maxDouble){
        double randNum = (double)rand() / INT_MAX;
        return randNum * (maxDouble - minDouble) + minDouble;
    }

    bool inCircle(double x0, double y0){
        return (x - x0) * (x - x0) + (y - y0) * (y - y0) <= r * r;
    }
};


int main() {

    return 0;
}