/// Source : https://leetcode.com/problems/long-pressed-name/
/// Author : liuyubobobo
/// Time   : 2018-10-20

#include <iostream>

using namespace std;


/// Two Pointers
/// Time Complexity: O(len(typed))
/// Space Complexity: O(1)
class Solution {
public:
    bool isLongPressedName(string name, string typed) {

        if (name[0] != typed[0])
            return false;

        int j = 1;
        for (int i = 1; i < name.size();)
            if (typed[j] == name[i])
                j++, i++;
            else if (typed[j] == name[i - 1])
                j++;
            else
                return false;
        return true;
    }
};


int main() {

    cout << Solution().isLongPressedName("alex", "aaleex") << endl;
    // true

    cout << Solution().isLongPressedName("saeed", "ssaaedd") << endl;
    // false

    cout << Solution().isLongPressedName("leelee", "lleeelee") << endl;
    // true

    cout << Solution().isLongPressedName("laiden", "laiden") << endl;
    // true

    return 0;
}