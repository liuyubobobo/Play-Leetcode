/// Source : https://leetcode.com/problems/unique-substrings-with-equal-digit-frequency/
/// Author : liuyubobobo
/// Time   : 2022-02-13

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


/// Presum + HashSet
/// Time Complexity: O(n^2)
/// Space Complexity: O(n^2)
class Solution {
public:
    int equalDigitFrequency(string s) {

        int n = s.size();

        vector<vector<int>> presum(n + 1, vector<int>(10, 0));
        for(int i = 0; i < s.size(); i ++){
            presum[i + 1][s[i] - '0'] ++;
            for(int j = 0; j < 10; j ++)
                presum[i + 1][j] += presum[i][j];
        }

        unordered_set<string> set;
        for(int r = 0; r < n; r ++){
            for(int l = 0; l <= r; l ++){
                int f = 0;
                bool ok = true;
                for(int k = 0; k < 10 && ok; k ++)
                    if(presum[r + 1][k] - presum[l][k]){
                        if(f && presum[r + 1][k] - presum[l][k] != f)
                            ok = false;
                        else f = presum[r + 1][k] - presum[l][k];
                    }
                if(ok) set.insert(s.substr(l, r - l + 1));
            }
        }
        return set.size();
    }
};


int main() {

    return 0;
}
