/// Source : https://leetcode.cn/problems/W2ZX4X/
/// Author : liuyubobobo
/// Time   : 2023-05-07

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Greedy
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    int runeReserve(vector<int>& runes) {

        sort(runes.begin(), runes.end());

        int n = runes.size(), start = 0, res = 0;
        while(start < n){
            int i;
            for(i = start + 1; i < n && runes[i] - runes[i - 1] <= 1; i ++);
            res = max(res, i - start);
            start = i;
        }
        return res;
    }
};


int main() {

    return 0;
}
