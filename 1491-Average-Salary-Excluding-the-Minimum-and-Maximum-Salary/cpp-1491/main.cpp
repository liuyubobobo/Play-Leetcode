/// Source : https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/submissions/
/// Author : liuyubobobo
/// Time   : 2020-06-27

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Sorting
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    double average(vector<int>& salary) {

        sort(salary.begin(), salary.end());
        return (double)accumulate(salary.begin() + 1, salary.end() - 1, 0) / (salary.size() - 2);
    }
};


int main() {

    return 0;
}
