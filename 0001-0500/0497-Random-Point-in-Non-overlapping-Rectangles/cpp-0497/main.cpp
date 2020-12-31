/// Source : https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/description/
/// Author : liuyubobobo
/// Time   : 2018-08-28

#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;


/// PreSum and Binary Search
/// Time Complexity: init: O(n)
///                  pick: O(logn)
/// Space Complexity: O(n)
class Solution {

private:
    vector<vector<int>> rects;
    vector<int> counts;

public:
    Solution(vector<vector<int>> rects): rects(rects.begin(), rects.end()) {

        counts.clear();
        counts.push_back(0);
        for(const vector<int>& rect: rects)
            counts.push_back(counts.back() + (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1));

//        cout << "couts : "; Solution::print_vec(counts);
    }

    vector<int> pick() {

        int randNum = rand() % counts.back();
        int index = lower_bound(counts.begin(), counts.end(), randNum) - counts.begin();
        if(counts[index] != randNum)
            index --;

        int offset = randNum - counts[index];

        // int m = rects[index][3] - rects[index][1] + 1;
        int n = rects[index][2] - rects[index][0] + 1;

//        cout << "rectangle : "; Solution::print_vec(rects[index]);
//        cout << "offset = " << offset << "; n = " << n << endl;

        return {rects[index][0] + offset % n, rects[index][1] + offset / n};
    }

    static void print_vec(const vector<int>& vec){
        for(int e: vec)
            cout << e << " ";
        cout << endl;
    }
};


int main() {

    vector<vector<int>> rects = {{-2, -2, -1, -1}, {1, 0, 3, 0}};
    Solution solution(rects);
    for(int i = 0; i < 5; i ++)
        Solution::print_vec(solution.pick());

    return 0;
}