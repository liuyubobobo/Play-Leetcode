/// Source : https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/
/// Author : liuyubobobo
/// Time   : 2021-09-04

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Sorting Tricks
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {

        int n = properties.size(), res = 0;

        sort(properties.begin(), properties.end(),
             [](const vector<int>& v1, const vector<int>& v2){

            if(v1[0] == v2[0]) return v1[1] > v2[1];
            return v1[0] < v2[0];
        });

        int maxd = 0;
        for(int i = n - 1; i >= 0; i --){
            res += properties[i][1] < maxd;
            maxd = max(maxd, properties[i][1]);
        }
        return res;
    }
};


int main() {

    vector<vector<int>> p1 = {{1, 1}, {2, 1}, {2, 2}, {1, 2}};
    cout << Solution().numberOfWeakCharacters(p1) << endl;
    // 1

    return 0;
}
