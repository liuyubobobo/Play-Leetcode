/// Source : https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/submissions/
/// Author : liuyubobobo
/// Time   : 2020-06-27

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Linear Scan
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    double average(vector<int>& salary) {

        int minv = *min_element(salary.begin(), salary.end());
        int maxv = *max_element(salary.begin(), salary.end());

        double sum = accumulate(salary.begin(), salary.end(), 0) - minv - maxv;
        return sum / (salary.size() - 2);
    }
};


int main() {

    return 0;
}
