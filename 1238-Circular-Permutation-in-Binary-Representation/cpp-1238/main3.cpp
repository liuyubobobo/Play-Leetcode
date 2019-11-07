/// Source : https://leetcode.com/problems/circular-permutation-in-binary-representation/
/// Author : liuyubobobo
/// Time   : 2019-11-06

#include <iostream>
#include <vector>

using namespace std;


/// Gray Code Formula
/// Time Complexity: O(2^n)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> circularPermutation(int n, int start) {

        vector<int> res;
        for(int i = 0; i < (1 << n); i ++)
            res.push_back(start ^ i ^ (i >> 1));
        return res;
    }
};


void print_vec(const vector<int>& res){

    for(int e: res) cout << e << " "; cout << endl;
}

int main() {

    print_vec(Solution().circularPermutation(2,3));
    // 3 2 0 1

    print_vec(Solution().circularPermutation(3,2));

    return 0;
}