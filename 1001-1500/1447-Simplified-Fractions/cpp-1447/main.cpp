/// Source : https://leetcode.com/problems/simplified-fractions/
/// Author : liuyubobobo
/// Time   : 2020-05-16

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


/// Brute Force + GCD + HashSet
/// Time Complexity: O(n^2)
/// Space Complexity: O(n^2)
class Solution {
public:
    vector<string> simplifiedFractions(int n) {

        unordered_set<string> res;
        for(int d = 2; d <= n; d ++)
            for(int i = 1; i < d; i ++){
                int g = gcd(d, i);
                res.insert(to_string(i / g) + "/" + to_string(d / g));
            }
        return vector<string>(res.begin(), res.end());
    }

private:
    int gcd(int a, int b){
        return b == 0 ? a : gcd(b, a % b);
    }
};


int main() {

    return 0;
}
