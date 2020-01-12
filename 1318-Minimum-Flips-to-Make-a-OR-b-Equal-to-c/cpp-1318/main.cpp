/// Source : https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/
/// Author : liuyubobobo
/// Time   : 2020-01-11

#include <iostream>
#include <vector>

using namespace std;


/// Convert every number into binary representation
/// Using array to store
/// Time Complexity: O(log(max(a, b, c)))
/// Space Complexity: O(log(max(a, b, c)))
class Solution {
public:
    int minFlips(int a, int b, int c) {

        vector<int> av = convert(a), bv = convert(b), cv = convert(c);

        int n = max(av.size(), max(bv.size(), cv.size()));
        while(av.size() < n) av.push_back(0);
        while(bv.size() < n) bv.push_back(0);
        while(cv.size() < n) cv.push_back(0);

        int res = 0;
        for(int i = 0; i < n; i ++)
            if(cv[i] == 0) res += av[i] + bv[i];
            else res += (av[i] || bv[i]) ? 0 : 1;
        return res;
    }

private:
    vector<int> convert(int x){
        vector<int> res;
        while(x) res.push_back(x % 2), x /= 2;
        return res;
    }
};


int main() {

    cout << Solution().minFlips(2, 6, 5) << endl;
    // 3

    cout << Solution().minFlips(4, 2, 7) << endl;
    // 1

    cout << Solution().minFlips(1, 2, 3) << endl;
    // 0

    return 0;
}
