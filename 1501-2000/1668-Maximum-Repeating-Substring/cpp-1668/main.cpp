/// Source : https://leetcode.com/problems/maximum-repeating-substring/
/// Author : liuyubobobo
/// Time   : 2020-11-28

#include <iostream>
#include <string>

using namespace std;


/// Brute Force
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {
public:
    int maxRepeating(string sequence, string word) {

        int res = 0;
        for(int i = 1; ; i ++){
            string t = "";
            for(int j = 0; j < i; j ++) t += word;
            if(sequence.find(t) == string::npos) break;
            res ++;
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
