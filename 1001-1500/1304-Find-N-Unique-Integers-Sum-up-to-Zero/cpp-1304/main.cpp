/// Source : https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/
/// Author : liuyubobobo
/// Time   : 2020-01-10

#include <iostream>
#include <vector>

using namespace std;


/// Generative
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> sumZero(int n) {

        vector<int> res;
        if(n % 2) res.push_back(0), n --;
        while(n) res.push_back(n), res.push_back(-n), n -= 2;
        return res;
    }
};


int main() {

    return 0;
}