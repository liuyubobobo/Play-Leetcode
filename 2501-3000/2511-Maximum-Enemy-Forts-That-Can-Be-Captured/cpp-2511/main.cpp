/// Source : https://leetcode.com/problems/maximum-enemy-forts-that-can-be-captured/description/
/// Author : liuyubobobo
/// Time   : 2022-12-28

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {
public:
    int captureForts(vector<int>& forts) {

        int n = forts.size(), res = 0;
        for(int i = 0; i < n; i ++){
            if(forts[i] != 1) continue;

            int j;
            for(j = i - 1; j >= 0 && forts[j] == 0; j --);
            if(j >= 0 && forts[j] == -1) res = max(res, i - j - 1);

            for(j = i + 1; j < n && forts[j] == 0; j ++);
            if(j < n && forts[j] == -1)  res = max(res, j - i - 1);
        }
        return res;
    }
};


int main() {

    return 0;
}
