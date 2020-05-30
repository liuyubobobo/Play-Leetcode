/// Source : https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/
/// Author : liuyubobobo
/// Time   : 2020-05-30

#include <iostream>
#include <unordered_set>

using namespace std;


/// HashSet. key type: String
/// Time Complexity: O(|s| * k)
/// Space Complexity: O(1 << k)
class Solution {
public:
    bool hasAllCodes(string s, int k) {

        unordered_set<string> set;
        for(int i = 0; i + k <= s.size(); i ++) set.insert(s.substr(i, k));
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

    return 0;
}
