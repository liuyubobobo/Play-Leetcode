/// Source : https://leetcode.com/problems/maximum-repeating-substring/
/// Author : liuyubobobo
/// Time   : 2020-11-28

#include <iostream>
#include <string>

using namespace std;


/// Two Pointers
/// Time Complexity: O(n^2)
/// Space Complexity: O(1)
class Solution {
public:
    int maxRepeating(string sequence, string word) {

        int res = 0;
        for(int i = 0; i < sequence.size(); i ++){
            int j;
            for(j = 0; i + j < sequence.size() && sequence[i + j] == word[j % word.size()]; j ++);
            res = max(res, j / (int)word.size());

        }
        return res;
    }
};


int main() {

    cout << Solution().maxRepeating("ababc", "ab") << endl;
    // 2

    cout << Solution().maxRepeating("ababc", "ba") << endl;
    // 1

    return 0;
}
