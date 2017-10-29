/// Source : https://leetcode.com/problems/range-addition/description/
/// Author : liuyubobobo
/// Time   : 2017-10-28

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/// Range Caching
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {

        vector<int> res(length, 0);
        for(vector<int> update: updates){
            int start = update[0];
            int end = update[1];
            int inc = update[2];

            res[start] += inc;
            if(end != length - 1)
                res[end + 1] -= inc;
        }

        for(int i = 1 ; i < length ; i ++)
            res[i] += res[i-1];

        return res;
    }
};

int main() {

    int length = 5;
    int updates[5][3] = {
            {1, 3, 2},
            {2, 4, 3},
            {0, 2, -2}
    };
    vector<vector<int>> vec;
    for(int i = 0 ; i < length ; i ++)
        vec.push_back(vector<int>(updates[i], updates[i] + sizeof(updates[i])/sizeof(int)));

    vector<int> res = Solution().getModifiedArray(length, vec);
    for(int e: res)
        cout << e << " ";
    cout << endl;

    return 0;
}