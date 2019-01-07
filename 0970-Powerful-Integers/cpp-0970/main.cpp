/// Source : https://leetcode.com/problems/powerful-integers/
/// Author : liuyubobobo
/// Time   : 2019-01-05

#include <iostream>
#include <unordered_set>
#include <vector>
#include <cmath>

using namespace std;


/// Brute Force
/// Time Complexity: O(log(bound)^2)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {

        unordered_set<int> res;
        for(int i = 0;;i ++){
            int powx = pow(x, i);
            if(powx > bound) break;
            for(int j = 0;;j ++) {
                int t = powx + pow(y, j);
                if(t > bound) break;
                res.insert(t);
                if(y == 1) break;
            }
            if(x == 1) break;
        }
        return vector<int>(res.begin(), res.end());
    }
};


int main() {

    return 0;
}