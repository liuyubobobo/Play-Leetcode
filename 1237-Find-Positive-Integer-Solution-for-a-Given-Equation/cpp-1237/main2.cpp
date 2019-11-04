/// Source : https://leetcode.com/problems/find-positive-integer-solution-for-a-given-equation/
/// Author : liuyubobobo
/// Time   : 2019-11-01

#include <iostream>
#include <vector>

using namespace std;


/// Binary Search
/// Time Complexity: O(1000 * log(1000))
/// Space Complexity: O(1)
class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {

        vector<vector<int>> res;
        for(int x = 1; x <= z; x ++){
            int l = 1, r = 1000;
            while(l <= r){
                int mid = (l + r) / 2;
                int v = customfunction.f(x, mid);
                if(v == z){
                    res.push_back({x, mid});
                    break;
                }
                else if(v < z) l = mid + 1;
                else r = mid - 1;
            }
        }
        return res;
    }
};


int main() {

    return 0;
}