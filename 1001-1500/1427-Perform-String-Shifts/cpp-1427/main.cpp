/// Source : https://leetcode.com/problems/perform-string-shifts/
/// Author : liuyubobobo
/// Time   : 2020-05-02

#include <iostream>
#include <vector>

using namespace std;


/// Mathematically to compute the net shifts
/// Time Complexity: O(|shift| + |s|)
/// Time Complexity: O(|s|)
class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {

        int right = 0;
        for(const vector<int>& v: shift)
            if(v[0]) right += v[1];
            else right -= v[1];

        if(right > 0){
            int offset = right % s.size();
            return s.substr(s.size() - offset) + s.substr(0, s.size() - offset);
        }

        int offset = (-right) % s.size();
        return s.substr(offset) + s.substr(0, offset);
    }
};


int main() {

    return 0;
}
