/// Source : https://leetcode.com/problems/counting-elements/
/// Author : liuyubobobo
/// Time   : 2020-05-02

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


/// Using HashSet
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int countElements(vector<int>& arr) {

        unordered_set<int> set;
        for(int e: arr) set.insert(e);

        int res = 0;
        for(int e: arr) if(set.count(e + 1)) res ++;
        return res;
    }
};


int main() {

    return 0;
}