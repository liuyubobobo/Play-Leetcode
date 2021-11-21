/// Source : https://leetcode.com/problems/two-furthest-houses-with-different-colors/
/// Author : liuyubobobo
/// Time   : 2021-11-20

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n^2)
/// Space Complexity: O(1)
class Solution {
public:
    int maxDistance(vector<int>& colors) {

        int res = 0;
        for(int i = 0; i < colors.size(); i ++)
            for(int j = i + 1; j < colors.size(); j ++)
                if(colors[i] != colors[j]) res = max(res, j - i);
        return res;
    }
};


int main() {

    return 0;
}
