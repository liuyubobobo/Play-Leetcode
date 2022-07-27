/// Source : https://leetcode.com/problems/rank-transform-of-an-array/
/// Author : liuyubobobo
/// Time   : 2022-07-27

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Using Map
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        map<int, int> rank;
        for(int e: arr) rank[e] = 0;

        int r = 1;
        for(const pair<int, int>& p: rank){
            rank[p.first] = r ++;
        }

        vector<int> res(arr.size());
        for(int i = 0; i < arr.size(); i ++)
            res[i] = rank[arr[i]];
        return res;
    }
};


int main() {

    return 0;
}
