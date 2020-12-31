/// Source : https://leetcode.com/problems/jewels-and-stones/description/
/// Author : liuyubobobo
/// Time   : 2018-01-27

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;


/// Using Hash Set
/// Time Complexity: O(len(J) + len(S))
/// Space Complxity: O(len(J))
class Solution {
public:
    int numJewelsInStones(string J, string S) {

        unordered_set<char> jewels;
        for(char c: J)
            jewels.insert(c);

        int res = 0;
        for(char c: S)
            if(jewels.find(c) != jewels.end())
                res ++;
        return res;
    }
};


int main() {

    cout << Solution().numJewelsInStones("aA", "aAAbbbb") << endl;
    cout << Solution().numJewelsInStones("z", "ZZ") << endl;

    return 0;
}