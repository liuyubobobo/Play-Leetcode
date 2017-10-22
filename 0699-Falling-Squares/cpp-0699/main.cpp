/// Source : https://leetcode.com/contest/leetcode-weekly-contest-54/problems/falling-squares/
/// Author : liuyubobobo
/// Time   : 2017-10-21

#include <iostream>
#include <vector>
using namespace std;

/// Using heights to record all the falling squares
/// Time Complexity: O(len(position)^2)
/// Space Complexity: O(len(position))
class Solution {

public:
    vector<int> fallingSquares(vector<pair<int, int>>& positions) {

        int n = positions.size();
        vector<int> heights(n, 0);
        for(int i = 0 ; i < positions.size() ; i ++){

            heights[i] = positions[i].second;
            for(int j = 0 ; j < i ; j ++)
                if(intersection(positions[j], positions[i]))
                    heights[i] = max(heights[i], heights[j] + positions[i].second);
        }

        vector<int> res(n, 0);
        res[0] = heights[0];
        for(int i = 1 ; i < n ; i ++)
            res[i] = max(heights[i], res[i-1]);

        return res;
    }

private:
    bool intersection(const pair<int, int>& a, const pair<int, int>& b){
        int l1 = a.first;
        int r1 = a.first + a.second - 1;
        int l2 = b.first;
        int r2 = b.first + b.second - 1;

        if(l1 > r2 || l2 > r1)
            return false;

        return true;
    }
};


void printVec(const vector<int>& vec){

    for(int i = 0 ; i < vec.size() ; i ++)
        cout << vec[i] << ((i == vec.size() - 1) ? '\n' : ' ');
}


int main() {

    vector<pair<int, int>> va;
    va.push_back(make_pair(1, 2));
    va.push_back(make_pair(2, 3));
    va.push_back(make_pair(6, 1));
    vector<int> res1 = Solution().fallingSquares(va);
    printVec(res1);


    vector<pair<int, int>> vb;
    vb.push_back(make_pair(100, 100));
    vb.push_back(make_pair(200, 100));
    vector<int> res2 = Solution().fallingSquares(vb);
    printVec(res2);

    return 0;
}