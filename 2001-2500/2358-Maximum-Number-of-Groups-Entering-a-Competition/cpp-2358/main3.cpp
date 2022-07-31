/// Source : https://leetcode.com/problems/maximum-number-of-groups-entering-a-competition/
/// Author : liuyubobobo
/// Time   : 2022-07-31

#include <iostream>
#include <vector>

using namespace std;


/// Greedy + Math
/// Time Complexity: O(log(n)) - sqrt is not O(1)
/// Space Complexity: O(1)
class Solution {
public:
    int maximumGroups(vector<int>& grades) {

        int n = grades.size();
        // (1 + x) * x / 2 <= n
        // x^2 + x - 2 * n <= 0

        return (int)((sqrt(1.0 + 8 * n) - 1.0) / 2.0);
    }
};


int main() {

    vector<int> x = {10,6,12,7,3,5};
    cout << Solution().maximumGroups(x) << '\n';
    // 3

    return 0;
}
