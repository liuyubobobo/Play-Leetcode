/// Source : https://leetcode.com/problems/check-if-string-is-transformable-with-substring-sort-operations/
/// Author : liuyubobobo
/// Time   : 2020-10-16

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// 10 queues in reverse order
/// see here for reference: https://leetcode.com/problems/check-if-string-is-transformable-with-substring-sort-operations/discuss/843927/Python-O(10*n)-using-queue
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

public:
    bool isTransformable(string s, string t) {

        vector<queue<int>> table(10);
        for(int i = s.size() - 1; i >= 0; i --)
            table[s[i] - '0'].push(i);

        for(int i = t.size() - 1; i >= 0; i --){
            int a = t[i] - '0';
            if(table[a].empty()) return false;

            for(int j = a + 1; j < 10; j ++)
                if(!table[j].empty() && table[j].front() > table[a].front()) return false;
            table[a].pop();
        }
        return true;
    }
};


int main() {

    cout << Solution().isTransformable("84532", "34852") << endl;
    // 1

    cout << Solution().isTransformable("34521", "23415") << endl;
    // 1

    cout << Solution().isTransformable("12345", "12435") << endl;
    // 0

    cout << Solution().isTransformable("1", "2") << endl;
    // 0

    cout << Solution().isTransformable("107595414", "150457194") << endl;
    // 0

    return 0;
}