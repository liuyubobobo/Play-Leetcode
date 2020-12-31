/// Source : https://leetcode.com/problems/diet-plan-performance/
/// Author : liuyubobobo
/// Time   : 2019-08-31

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Sliding Window
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {

        int n = calories.size();
        int res = 0;
        int cur = accumulate(calories.begin(), calories.begin() + (k - 1), 0);
        for(int i = k - 1; i < n; i ++){
            cur += calories[i];
            if(cur < lower) res --;
            else if(cur > upper) res ++;
            cur -= calories[i - (k - 1)];
        }
        return res;
    }
};


int main() {

    vector<int> calories1 = {1,2,3,4,5};
    cout << Solution().dietPlanPerformance(calories1, 1, 3, 3) << endl;
    // 0

    vector<int> calories2 = {3, 2};
    cout << Solution().dietPlanPerformance(calories2, 2, 0, 1) << endl;
    // 1

    vector<int> calories3 = {6, 5, 0, 0};
    cout << Solution().dietPlanPerformance(calories3, 2, 1, 5) << endl;
    // 0

    vector<int> calories4 = {6,13,8,7,10,1,12,11};
    cout << Solution().dietPlanPerformance(calories4, 6, 5, 37) << endl;
    // 3

    return 0;
}