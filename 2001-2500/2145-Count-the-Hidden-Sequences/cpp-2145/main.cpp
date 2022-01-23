/// Source : https://leetcode.com/problems/count-the-hidden-sequences/
/// Author : liuyubobobo
/// Time   : 2022-01-22

#include <iostream>
#include <vector>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {

        int n = differences.size();

        long long minv = differences[0], maxv = differences[0];
        long long cur = differences[0];
        for(int i = 1; i < n; i ++)
            cur += differences[i], minv = min(minv, cur), maxv = max(maxv, cur);

        int l = max(lower, (int)(lower - minv)), r = min(upper, (int)(upper - maxv));
        return max(0, r - l + 1);
    }
};


int main() {

    vector<int> diff1 = {1, -3, 4};
    cout << Solution().numberOfArrays(diff1, 1, 6) << endl;
    // 2

    vector<int> diff2 = {3, -4, 5, 1, -2};
    cout << Solution().numberOfArrays(diff2, -4, 5) << endl;
    // 4

    vector<int> diff3 = {4, -7, 2};
    cout << Solution().numberOfArrays(diff3, 3, 6) << endl;
    // 0

    vector<int> diff4 = {-40};
    cout << Solution().numberOfArrays(diff4, -46, 53) << endl;
    // 60

    return 0;
}
