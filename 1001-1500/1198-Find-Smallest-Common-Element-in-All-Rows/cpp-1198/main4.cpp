/// Source : https://leetcode.com/problems/find-smallest-common-element-in-all-rows/
/// Author : liuyubobobo
/// Time   : 2019-09-21

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Binary Search
/// Time Complexity: O(m * n * log m * n)
/// Space Complexity: O(1)
class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {

        for(int e: mat[0]){

            int i;
            for(i = 1; i < mat.size(); i ++){
                vector<int>::const_iterator iter = lower_bound(mat[i].begin(), mat[i].end(), e);
                if(iter == mat[i].end() || *iter != e) break;
            }

            if(i == mat.size()) return e;
        }
        return -1;
    }
};


int main() {

    vector<vector<int>> mat1 = {
            {1,2,3,4,5},{2,4,5,8,10},{3,5,7,9,11},{1,3,5,7,9}
    };
    cout << Solution().smallestCommonElement(mat1) << endl;

    return 0;
}