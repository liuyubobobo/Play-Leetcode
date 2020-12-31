/// Source : https://leetcode.com/problems/find-smallest-common-element-in-all-rows/
/// Author : liuyubobobo
/// Time   : 2019-09-21

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Using TreeSet
/// Time Complexity: O(m * n * log m * n)
/// Space Complexity: O(m * n)
class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {

        set<int> set1;
        for(int e: mat[0]) set1.insert(e);

        for(int i = 1; i < mat.size(); i ++){

            set<int> set2;
            for(int e: mat[i]) if(set1.count(e)) set2.insert(e);
            set1 = set2;
        }

        return set1.size() ? *set1.begin() : -1;
    }
};


int main() {

    return 0;
}