/// Source : https://leetcode.com/problems/optimal-partition-of-string/
/// Author : liuyubobobo
/// Time   : 2022-09-10

#include <iostream>
#include <vector>

using namespace std;


/// Greedy
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int partitionString(string s) {

        vector<bool> used(26, false);
        int res = 1;
        for(char c: s){
            if(used[c - 'a']){
                res ++;
                used.assign(26, false);
            }
            used[c - 'a'] = true;
        }
        return res;
    }
};


int main() {


    return 0;
}
