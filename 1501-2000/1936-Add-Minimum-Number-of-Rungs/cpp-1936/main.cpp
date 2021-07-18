/// Source : https://leetcode.com/problems/add-minimum-number-of-rungs/
/// Author : liuyubobobo
/// Time   : 2021-07-17

#include <iostream>
#include <vector>

using namespace std;


/// Greedy
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {


        int res = 0;
        for(int i = 0; i < rungs.size(); i ++){
            int d = rungs[i] - (i == 0 ? 0 : rungs[i - 1]);
            if(d <= dist) continue;
            res += (d / dist + !!(d % dist)) - 1;
        }
        return res;
    }
};


int main() {

    vector<int> a1 = {1, 3, 5, 10};
    cout << Solution().addRungs(a1, 2) << endl;
    // 2

    vector<int> a2 = {3, 6, 8, 10};
    cout << Solution().addRungs(a2, 3) << endl;
    // 0

    vector<int> a3 = {3, 4, 6, 7};
    cout << Solution().addRungs(a3, 2) << endl;
    // 1

    vector<int> a4 = {5};
    cout << Solution().addRungs(a4, 10) << endl;
    // 0

    return 0;
}
