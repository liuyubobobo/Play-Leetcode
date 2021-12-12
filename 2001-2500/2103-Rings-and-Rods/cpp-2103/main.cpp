/// Source : https://leetcode.com/problems/rings-and-rods/
/// Author : liuyubobobo
/// Time   : 2021-12-11

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Brute Force
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int countPoints(string rings) {

        vector<set<char>> poles(10);
        for(int i = 0; i < rings.size(); i += 2)
            poles[rings[i + 1] - '0'].insert(rings[i]);

        int res = 0;
        for(int i = 0; i < 10; i ++)
            res += poles[i].size() == 3;
        return res;
    }
};


int main() {

    return 0;
}
