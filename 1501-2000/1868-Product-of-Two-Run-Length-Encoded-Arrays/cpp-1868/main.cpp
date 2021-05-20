/// Source : https://leetcode.com/problems/product-of-two-run-length-encoded-arrays/
/// Author : liuyubobobo
/// Time   : 2021-05-20

#include <iostream>
#include <vector>

using namespace std;


/// Two Pointers
/// Time Complexity: O(|endcode1| + |encode2|)
/// Space Compelxity: O(1)
class Solution {
public:
    vector<vector<int>> findRLEArray(vector<vector<int>>& encoded1, vector<vector<int>>& encoded2) {

        vector<vector<int>> res;
        int i = 0, j = 0;
        while(i < encoded1.size() && j < encoded2.size()){

            int f = min(encoded1[i][1], encoded2[j][1]);
            int v = encoded1[i][0] * encoded2[j][0];
            if(!res.empty() && res.back()[0] == v) res.back()[1] += f;
            else res.push_back({v, f});

            encoded1[i][1] -= f;
            if(encoded1[i][1] == 0) i ++;

            encoded2[j][1] -= f;
            if(encoded2[j][1] == 0) j ++;
        }
        return res;
    }
};


int main() {

    return 0;
}
