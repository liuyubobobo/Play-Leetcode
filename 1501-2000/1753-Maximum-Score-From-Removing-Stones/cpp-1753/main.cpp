/// Source : https://leetcode.com/problems/maximum-score-from-removing-stones/
/// Author : liuyubobobo
/// Time   : 2021-02-06

#include <iostream>
#include <vector>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(min(a, b, c))
/// Space Complexity: O(1)
class Solution {
public:
    int maximumScore(int a, int b, int c) {

        vector<int> v = {a, b, c};
        sort(v.begin(), v.end());

        int limit = min(a, b);
        int res = 0;
        for(int i = 0; i <= limit; i ++)
            res = max(res, i + solve(v[0] - i, v[1] - i, v[2]));
        return res;
    }

private:
    int solve(int a, int b, int c){
        return min(a + b, c);
    }
};


int main() {

    cout << Solution().maximumScore(2, 4, 6) << endl;
    // 6

    cout << Solution().maximumScore(4, 4, 6) << endl;
    // 7

    cout << Solution().maximumScore(1, 8, 8) << endl;
    // 8

    return 0;
}
