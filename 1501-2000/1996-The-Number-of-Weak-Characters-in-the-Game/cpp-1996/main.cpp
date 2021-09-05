/// Source : https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/
/// Author : liuyubobobo
/// Time   : 2021-09-04

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Binary Search
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {

        int n = properties.size(), res = 0;

        sort(properties.begin(), properties.end());
        for(int i = n - 2; i >= 0; i --){
            vector<int> t = {properties[i][0] + 1, INT_MIN};
            vector<vector<int>>::iterator iter = lower_bound(properties.begin(), properties.end(), t);
            if(iter != properties.end() && properties[i][1] < (*iter)[1]) res ++;
            properties[i][1] = max(properties[i][1], properties[i + 1][1]);
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
