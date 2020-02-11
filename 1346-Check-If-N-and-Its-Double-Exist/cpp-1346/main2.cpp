/// Source : https://leetcode.com/problems/simplify-path/
/// Author : liuyubobobo
/// Time   : 2019-02-10

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Using set
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {

        set<int> set;
        for(int e: arr) {
            if (e % 2 == 0 && set.count(e / 2)) return true;
            else if (set.count(e * 2)) return true;
            set.insert(e);
        }
        return false;
    }
};


int main() {

    return 0;
}
