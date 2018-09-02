/// Source : https://leetcode.com/problems/bitwise-ors-of-subarrays/description/
/// Author : liuyubobobo
/// Time   : 2018-09-02

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


/// Frontier Hash Set
/// Time Complexity: O(n*log(max_number))
/// Space Complexity: O(n*log(max_number))
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {

        unordered_set<int> res;
        unordered_set<int> frontier;
        unordered_set<int> cur;
        for(int a: A){
            cur.clear();
            cur.insert(a);
            for(int x: frontier)
                cur.insert(x | a);

            res.insert(cur.begin(), cur.end());
            frontier = cur;
        }

        return res.size();
    }
};


int main() {

    return 0;
}