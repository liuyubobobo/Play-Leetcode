/// Source : https://leetcode.com/problems/maximize-distance-to-closest-person/
/// Author : liuyubobobo
/// Time   : 2022-01-16

#include <iostream>
#include <vector>

using namespace std;


/// Linear Scan
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {

        vector<int> pos;
        for(int i = 0; i < seats.size(); i ++)
            if(seats[i]) pos.push_back(i);

        int res = max(pos[0], (int)seats.size() - 1 - pos.back());
        for(int i = 0; i + 1 < pos.size(); i ++)
            res = max(res, (pos[i + 1] - pos[i]) / 2);
        return res;
    }
};


int main() {

    return 0;
}
