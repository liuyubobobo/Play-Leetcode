/// Source : https://leetcode.com/problems/unique-binary-search-trees/description/
/// Author : liuyubobobo
/// Time   : 2018-09-10

#include <iostream>
#include <vector>

using namespace std;


/// Mathematics
/// It's Catalan Number!
/// See more about Catalan number here:
/// https://en.wikipedia.org/wiki/Catalan_number
///
/// Time Complexity: O(n)
/// Space Complexity: O(1)

class Solution {

public:
    int numTrees(int n) {

        long long C = 1ll;
        for(int i = 0; i < n; i ++)
            C = C * 2 * (2 * i + 1) / (i + 2);
        return C;
    }
};


int main() {

    cout << Solution().numTrees(3) << endl;

    return 0;
}