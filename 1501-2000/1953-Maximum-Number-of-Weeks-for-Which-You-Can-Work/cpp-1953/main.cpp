/// Source : https://leetcode.com/problems/maximum-number-of-weeks-for-which-you-can-work/
/// Author : liuyubobobo
/// Time   : 2021-07-31

#include <iostream>
#include <vector>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {

        long long sum = 0ll, maxv = 0ll;
        for(int e: milestones)
            sum += e, maxv = max(maxv, (long long)e);

        sum -= maxv;

        if(sum >= maxv) return sum + maxv;
        else return sum * 2ll + 1ll;
    }
};


int main() {

    vector<int> milestones1 = {1, 2, 3};
    cout << Solution().numberOfWeeks(milestones1) << endl;
    // 6

    vector<int> milestones2 = {5, 2, 1};
    cout << Solution().numberOfWeeks(milestones2) << endl;
    // 7

    return 0;
}
