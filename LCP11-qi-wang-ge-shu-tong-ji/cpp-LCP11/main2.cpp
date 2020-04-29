/// Source : https://leetcode-cn.com/problems/qi-wang-ge-shu-tong-ji/
/// Author : liuyubobobo
/// Time   : 2020-04-29

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


/// Using Hash Set
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int expectNumber(vector<int>& scores) {

        unordered_set<int> set;
        for(int e: scores) set.insert(e);
        return set.size();
    }
};


int main() {

    vector<int> scores1 = {1, 2, 3};
    cout << Solution().expectNumber(scores1) << endl;
    // 3

    vector<int> scores2 = {1, 1};
    cout << Solution().expectNumber(scores2) << endl;
    // 1

    vector<int> scores3 = {1, 1, 2};
    cout << Solution().expectNumber(scores3) << endl;
    // 2

    return 0;
}
