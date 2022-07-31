/// Source : https://leetcode.com/problems/maximum-number-of-groups-entering-a-competition/
/// Author : liuyubobobo
/// Time   : 2022-07-31

#include <iostream>
#include <vector>

using namespace std;


/// Greedy
/// Time Complexity: O(sqrt(n))
/// Space Complexity: O(1)
class Solution {
public:
    int maximumGroups(vector<int>& grades) {

        int n = grades.size();
        for(int k = 1; ;k ++)
            if((1 + k) * k / 2 >= n){
                return ((1 + k) * k / 2 == n) ? k : (k - 1);
            }
        return 0;
    }
};


int main() {

    vector<int> x = {10,6,12,7,3,5};
    cout << Solution().maximumGroups(x) << '\n';
    // 3

    return 0;
}
