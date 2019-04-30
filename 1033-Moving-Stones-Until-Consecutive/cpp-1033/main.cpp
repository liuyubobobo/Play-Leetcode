/// Source : https://leetcode.com/problems/moving-stones-until-consecutive/
/// Author : liuyubobobo
/// Time   : 2019-04-27

#include <iostream>
#include <vector>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(1)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {

        vector<int> A = {a, b, c};
        sort(A.begin(), A.end());

        int min_res = 2;
        if(A[1] - A[0] == 1 && A[2] - A[1] == 1)
            min_res = 0;
        else if(A[1] - A[0] <= 2 || A[2] - A[1] <= 2)
            min_res = 1;

        int max_res = (A[1] - A[0] - 1) + (A[2] - A[1] - 1);
        return {min_res, max_res};
    }
};


int main() {

    vector<int> res1 = Solution().numMovesStones(3, 5, 1);
    cout << res1[0] << " " << res1[1] << endl;
    // 1 2

    vector<int> res2 = Solution().numMovesStones(1, 2, 5);
    cout << res2[0] << " " << res2[1] << endl;
    // 1 2

    return 0;
}