/// Source : https://leetcode.com/problems/slowest-key/
/// Author : liuyubobobo
/// Time   : 2020-10-24

#include <iostream>
#include <vector>

using namespace std;


/// Linear Scan
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {

        vector<int> t(26, 0);
        for(int i = 0; i < keysPressed.size(); i ++)
            t[keysPressed[i] - 'a'] = max(t[keysPressed[i] - 'a'],
                                          (i == 0) ? releaseTimes[i] : (releaseTimes[i] - releaseTimes[i - 1]));

        int maxv = t[0], res = 0;
        for(int i = 1; i < 26; i ++)
            if(t[i] >= maxv) res = i, maxv = t[i];
        return 'a' + res;
    }
};


int main() {

    vector<int> releasTime1 = {9,29,49,50};
    cout << Solution().slowestKey(releasTime1, "cbcd") << endl;
    // c

    vector<int> releasTime2 = {12,23,36,46,62};
    cout << Solution().slowestKey(releasTime2, "spuda") << endl;
    // a

    return 0;
}
