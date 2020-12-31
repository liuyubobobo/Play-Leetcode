/// Source : https://leetcode.com/problems/maximum-number-of-ones/
/// Author : liuyubobobo
/// Time   : 2019-09-07

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Mathematics
/// Time Complexity: O(width * height + (side ^ 2)log(side^2) + maxOnes)
/// Space Complexity: O((side ^ 2)log(side^2))
class Solution {
public:
    int maximumNumberOfOnes(int width, int height, int side, int maxOnes) {

        vector<int> pattern(side * side, 0);
        for(int i = 0; i < width; i ++)
            for(int j = 0; j < height; j ++)
                pattern[i % side * side + j % side] ++;

        sort(pattern.begin(), pattern.end(), greater<int>());
        return accumulate(pattern.begin(), pattern.begin() + maxOnes, 0);
    }
};


int main() {

    cout << Solution().maximumNumberOfOnes(3, 3, 2, 1) << endl;
    // 4

    cout << Solution().maximumNumberOfOnes(3, 3, 2, 2) << endl;
    // 6

    cout << Solution().maximumNumberOfOnes(68, 86, 63, 1474) << endl;
    // 3178

    cout << Solution().maximumNumberOfOnes(86, 32, 3, 4) << endl;
    // 1276

    return 0;
}