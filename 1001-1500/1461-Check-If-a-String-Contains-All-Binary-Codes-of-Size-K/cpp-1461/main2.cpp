/// Source : https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/
/// Author : liuyubobobo
/// Time   : 2020-05-30
/// Updated: 2022-05-30

#include <iostream>
#include <unordered_set>

using namespace std;


/// HashSet. key type: Integer
/// Time Complexity: O(|s|)
/// Space Complexity: O(1 << k)
class Solution {
public:
    bool hasAllCodes(string s, int k) {

        if(k >= s.size()) return false;

        int cur = 0;
        for(int i = 0; i < k - 1; i ++)
            cur = 2 * cur + (s[i] == '1');

        unordered_set<int> set;
        for(int i = k - 1; i < (int)s.size(); i ++){
            cur = cur * 2 + (s[i] == '1');
            set.insert(cur);
            cur &= ~(1 << (k - 1));
        }
        return set.size() == (1 << k);
    }
};


int main() {

    cout << Solution().hasAllCodes("00110110", 2) << endl;
    // 1

    cout << Solution().hasAllCodes("00110", 2) << endl;
    // 1

    cout << Solution().hasAllCodes("0110", 1) << endl;
    // 1

    cout << Solution().hasAllCodes("0110", 2) << endl;
    // 0

    cout << Solution().hasAllCodes("0000000001011100", 4) << endl;
    // 0

    cout << Solution().hasAllCodes("0", 20) << endl;
    // 0

    return 0;
}
