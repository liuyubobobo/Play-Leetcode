/// Source : https://leetcode.com/problems/find-missing-observations/
/// Author : liuyubobobo
/// Time   : 2021-10-02

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Greedy
/// Time Complexity : O(m + n)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {

        int m = rolls.size(), rolls_sum = accumulate(rolls.begin(), rolls.end(), 0);

        int total = mean * (m + n), left_total = total - rolls_sum;

        if(n <= left_total && left_total <= 6 * n){

            vector<int> res(n, 1);
            left_total -= n;
            for(int i = 0; i < n && left_total; i ++){
                int t = min(5, left_total);
                res[i] += t;
                left_total -= t;
            }
            return res;
        }
        return {};
    }
};


void print_vec(const vector<int>& v){
    for(int e: v) cout << e << ' '; cout << '\n';
}

int main() {

    vector<int> rolls1 = {3, 2, 4, 3};
    print_vec(Solution().missingRolls(rolls1, 4, 2));
    // 6 6

    vector<int> rolls2 = {1, 5, 6};
    print_vec(Solution().missingRolls(rolls2, 3, 4));
    // 2 3 2 2

    vector<int> rolls3 = {1, 2, 3, 4};
    print_vec(Solution().missingRolls(rolls3, 6, 4));
    // empty

    vector<int> rolls4 = {1};
    print_vec(Solution().missingRolls(rolls4, 3, 1));
    // 5

    return 0;
}
