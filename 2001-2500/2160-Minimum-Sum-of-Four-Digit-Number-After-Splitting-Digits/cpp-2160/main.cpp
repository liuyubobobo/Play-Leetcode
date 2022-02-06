/// Source : https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits/
/// Author : liuyubobobo
/// Time   : 2022-02-06

#include <iostream>
#include <vector>
#include <climits>

using namespace std;


/// Brute Force
/// Time Complexity: O(4! * 3 * 4)
/// Space Complexity: O(1)
class Solution {
public:
    int minimumSum(int num) {

        string s = to_string(num);
        sort(s.begin(), s.end());

        int res = INT_MAX;
        do{
            for(int i = 1; i < 4; i ++)
                res = min(res, atoi(s.substr(0, i).c_str()) + atoi(s.substr(i).c_str()));
        }while(next_permutation(s.begin(), s.end()));

        return res;
    }
};


int main() {

    return 0;
}
