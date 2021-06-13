/// Source : https://leetcode.com/problems/merge-triplets-to-form-target-triplet/
/// Author : liuyubobobo
/// Time   : 2021-06-12

#include <iostream>
#include <vector>

using namespace std;


/// Greedy
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {

        vector<int> res(3, 0);
        for(const vector<int>& e: triplets)
            if(e[0] <= target[0] && e[1] <= target[1] && e[2] <= target[2])
                res[0] = max(res[0], e[0]), res[1] = max(res[1], e[1]), res[2] = max(res[2], e[2]);
        return res == target;
    }
};


int main() {

    vector<vector<int>> triplets1 = {{2, 5, 3}, {1, 8, 4}, {1, 7, 5}};
    vector<int> target1 = {2, 7, 5};
    cout << Solution().mergeTriplets(triplets1, target1) << endl;
    // 1

    vector<vector<int>> triplets2 = {{1, 3, 4}, {2, 5, 8}};
    vector<int> target2 = {2, 5, 8};
    cout << Solution().mergeTriplets(triplets2, target2) << endl;
    // 1

    vector<vector<int>> triplets3 = {{2, 5, 3}, {2, 3, 4}, {1, 2, 5}, {5, 2, 3}};
    vector<int> target3 = {5, 5, 5};
    cout << Solution().mergeTriplets(triplets3, target3) << endl;
    // 1

    vector<vector<int>> triplets4 = {{3, 4, 5}, {4, 5, 6}};
    vector<int> target4 = {3, 2, 5};
    cout << Solution().mergeTriplets(triplets4, target4) << endl;
    // 0

    return 0;
}
