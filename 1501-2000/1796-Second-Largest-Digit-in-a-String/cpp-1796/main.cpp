/// Source : https://leetcode.com/problems/second-largest-digit-in-a-string/
/// Author : liuyubobobo
/// Time   : 2021-03-21

#include <iostream>
#include <set>

using namespace std;


/// Using Set
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int secondHighest(string s) {

        set<int> d;
        for(char c: s)
            if(isdigit(c)) d.insert(c - '0');

        if(d.size() <= 1) return -1;

        set<int>::reverse_iterator iter = d.rbegin();
        iter ++;
        return *iter;
    }
};


int main() {

    cout << Solution().secondHighest("ck077") << endl;
    // 0

    return 0;
}
