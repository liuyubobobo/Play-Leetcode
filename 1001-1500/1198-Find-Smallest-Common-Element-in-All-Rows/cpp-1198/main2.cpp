/// Source : https://leetcode.com/problems/find-smallest-common-element-in-all-rows/
/// Author : liuyubobobo
/// Time   : 2019-09-21

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


/// Using HashSet
/// Time Complexity: O(m * n)
/// Space Complexity: O(m * n)
class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {

        unordered_set<int> set1;
        for(int e: mat[0]) set1.insert(e);

        for(int i = 1; i < mat.size(); i ++){

            unordered_set<int> set2;
            for(int e: mat[i]) if(set1.count(e)) set2.insert(e);
            set1 = set2;
        }

        return set1.size() ? *min_element(set1.begin(), set1.end()) : -1;
    }
};


int main() {

    return 0;
}