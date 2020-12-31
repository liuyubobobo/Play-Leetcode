/// Source : https://leetcode.com/problems/pancake-sorting/
/// Author : liuyubobobo
/// Time   : 2018-01-05

#include <iostream>
#include <vector>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {

        int n = A.size();

        vector<int> res;
        for(int i = n - 1; i >= 0; i --){

            int max_index = find(A.begin(), A.end(), i + 1) - A.begin();
            res.push_back(max_index + 1);
            reverse(A.begin(), A.begin() + max_index + 1);
            res.push_back(i + 1);
            reverse(A.begin(), A.begin() + i + 1);
        }
        return res;
    }
};


int main() {

    return 0;
}