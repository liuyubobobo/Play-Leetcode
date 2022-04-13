/// Source : https://leetcode-cn.com/contest/cmbchina-2022spring/problems/ReWLAw/
/// Author : liuyubobobo
/// Time   : 2022-04-13

#include <iostream>
#include <vector>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int numFlowers(vector<vector<int>>& roads) {

        int n = roads.size() + 1;
        vector<int> degrees(n);
        for(const vector<int>& road: roads){
            degrees[road[0]] ++;
            degrees[road[1]] ++;
        }
        return *max_element(degrees.begin(), degrees.end()) + 1;
    }
};


int main() {

    vector<vector<int>> roads1 = {{0, 1}, {1, 3}, {1, 2}};
    cout << Solution().numFlowers(roads1) << '\n';
    // 4

    return 0;
}
