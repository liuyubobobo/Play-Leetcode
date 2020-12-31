/// Source : https://leetcode.com/problems/jewels-and-stones/description/
/// Author : liuyubobobo
/// Time   : 2018-10-06

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;


/// Brute Force
/// Time Complexity: O(len(J) * len(S))
/// Space Complxity: O(1)
class Solution {
public:
    int numJewelsInStones(string J, string S) {

        int res = 0;
        for(char c: S)
            if(J.find(c) != string::npos)
                res ++;
        return res;
    }
};


int main() {

    cout << Solution().numJewelsInStones("aA", "aAAbbbb") << endl;
    cout << Solution().numJewelsInStones("z", "ZZ") << endl;

    return 0;
}