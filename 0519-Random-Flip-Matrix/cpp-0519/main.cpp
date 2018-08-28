/// Source : https://leetcode.com/problems/random-flip-matrix/description/
/// Author : liuyubobobo
/// Time   : 2018-08-28

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


/// Rejection Sampling
///
/// Time Complexty: O(m*n)
/// Space Complexity: O(min(len(call of flip), m*n))
class Solution {

private:
    int m, n;
    unordered_set<int> ones;

public:
    Solution(int n_rows, int n_cols): m(n_rows), n(n_cols) {
        ones.clear();
    }

    vector<int> flip() {

        int randNum;
        do{
            randNum = rand() % (m * n);
        }while(ones.find(randNum) != ones.end());
        ones.insert(randNum);
        return {randNum / n, randNum % n};
    }

    void reset() {
        ones.clear();
    }
};


int main() {

    return 0;
}