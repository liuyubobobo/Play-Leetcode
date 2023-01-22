/// Source : https://leetcode.com/problems/sort-the-students-by-their-kth-score/description/
/// Author : liuyubobobo
/// Time   : 2023-01-21

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Sorting
/// Time Complexity: O(mlogm * n)
/// Space Cpomplexity: O(n)
class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {

        sort(score.begin(), score.end(),
             [k](const vector<int>& s1, const vector<int>& s2){
            return s1[k] > s2[k];
        });
        return score;
    }
};


int main() {

    return 0;
}
