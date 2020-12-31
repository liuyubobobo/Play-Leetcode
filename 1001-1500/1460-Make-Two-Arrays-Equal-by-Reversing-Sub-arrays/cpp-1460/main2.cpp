/// Source : https://leetcode.com/problems/make-two-arrays-equal-by-reversing-sub-arrays/
/// Author : liuyubobobo
/// Time   : 2020-05-30

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Using Hash Map
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {

        unordered_map<int, int> f1, f2;
        for(int i = 0; i < target.size(); i ++)
            f1[target[i]] ++, f2[arr[i]] ++;
        return f1 == f2;
    }
};


int main() {

    return 0;
}
