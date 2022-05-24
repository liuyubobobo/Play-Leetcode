/// Source : https://leetcode.com/problems/unique-substrings-in-wraparound-string/
/// Author : liuyubobobo
/// Time   : 2022-05-24

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Linear Scan
/// Time Complexity: O(1)
/// Space Complexity: O(1)
class Solution {
public:
    int findSubstringInWraproundString(string p) {

        vector<int> len(26, 0);
        for(int start = 0, i = 1; i <= p.size(); i ++)
            if(i == p.size() || ((p[start] - 'a') + (i - start)) % 26 != (p[i] - 'a')){

                int l = i - start;
                for(int j = start; j < i; j ++)
                    len[p[j] - 'a'] = max(len[p[j] - 'a'], l --);
                start = i;
            }

        return accumulate(len.begin(), len.end(), 0);
    }
};


int main() {

    cout << Solution().findSubstringInWraproundString("a") << '\n';
    // 1

    cout << Solution().findSubstringInWraproundString("cac") << '\n';
    // 2

    cout << Solution().findSubstringInWraproundString("zab") << '\n';
    // 6

    return 0;
}
