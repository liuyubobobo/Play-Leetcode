/// Source : https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i/description/
/// Author : liuyubobobo
/// Time   : 2023-02-04

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Two Pointers
/// Time Complexity: O(|banned| * log|banned| + n + |banned|)
/// Space Complexity: O(1)
class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {

        sort(banned.begin(), banned.end());

        int banned_index = 0, res = 0, sum = 0;
        for(int i = 1; i <= n; i ++){
            if(banned_index < banned.size() && i == banned[banned_index]){
                while(banned_index < banned.size() && i == banned[banned_index])
                    banned_index ++;
            }
            else if(sum + i > maxSum) break;
            else{
                res ++;
                sum += i;
            }
        }
        return res;
    }
};


int main() {

    return 0;
}
