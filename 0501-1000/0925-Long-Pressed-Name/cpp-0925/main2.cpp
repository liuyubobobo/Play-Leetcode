/// Source : https://leetcode.com/problems/long-pressed-name/
/// Author : liuyubobobo
/// Time   : 2018-10-21

#include <iostream>
#include <vector>

using namespace std;


/// Split the name and typed by characters
/// Do not use vector to store the split result :-)
///
/// Time Complexity: O(len(typed) + len(name))
/// Space Complexity: O(1)
class Solution {

public:
    bool isLongPressedName(string name, string typed) {

        int start1 = 0, start2 = 0;
        for(int i1 = start1 + 1; i1 <= name.size(); i1 ++)
            if(i1 == name.size() || name[i1] != name[start1]){

                if(start2 >= typed.size())
                    return false;

                for(int i2 = start2 + 1; i2 <= typed.size(); i2 ++)
                    if(i2 == typed.size() || typed[i2] != typed[start2]){

                        if(typed[start2] != name[start1] || i2 - start2 < i1 - start1)
                            return false;

                        start2 = i2;
                        break;
                    }

                start1 = i1;
            }

        return start1 == name.size();
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