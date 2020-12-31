/// Source : https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer/
/// Author : liuyubobobo
/// Time   : 2020-05-02

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(9 * 9 ( lognum)
/// Space Complexity: O(1)
class Solution {
public:
    int maxDiff(int num) {

        vector<int> v;
        while(num) v.push_back(num % 10), num /= 10;
        reverse(v.begin(), v.end());

        int minv = INT_MAX, maxv = INT_MIN;
        for(int x = 0; x <= 9; x ++)
            for(int y = 0; y <= 9; y ++){
                vector<int> t = v;
                for(int& e: t) if(e == x) e = y;
                if(t[0] == 0) continue;

                int x = 0;
                for(int e: t) x = x * 10 + e;
                minv = min(minv, x);
                maxv = max(maxv, x);
            }
        return maxv - minv;
    }
};


int main() {

    cout << Solution().maxDiff(555) << endl;

    return 0;
}
