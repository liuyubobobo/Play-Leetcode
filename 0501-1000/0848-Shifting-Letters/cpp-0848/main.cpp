/// Source : https://leetcode.com/problems/shifting-letters/
/// Author : liuyubobobo
/// Time   : 2021-09-08

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {

        int n = s.size();
        vector<long long> v(n, shifts.back());
        for(int i = n - 2; i >= 0; i --)
            v[i] = v[i + 1] + shifts[i];

        for(int i = 0; i < s.size(); i ++)
            s[i] = 'a' + (v[i] + s[i] - 'a') % 26ll;
        return s;
    }
};


int main() {

    return 0;
}
