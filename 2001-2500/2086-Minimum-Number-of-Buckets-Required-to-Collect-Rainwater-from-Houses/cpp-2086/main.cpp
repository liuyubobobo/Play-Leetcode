/// Source : https://leetcode.com/problems/minimum-number-of-buckets-required-to-collect-rainwater-from-houses/
/// Author : liuyubobobo
/// Time   : 2021-11-27

#include <iostream>
#include <vector>

using namespace std;


/// Greedy
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int minimumBuckets(string s) {

        int n = s.size();
        int res = 0;
        for(int i = 0; i < n; i ++)
            if(s[i] == 'H'){
                if(i - 1 >= 0 && s[i - 1] == 'W') continue;
                else if(i + 1 < n && s[i + 1] == '.'){s[i + 1] = 'W', res ++;}
                else if(i - 1 >= 0 && s[i - 1] == '.'){s[i - 1] = 'W', res ++;}
                else return -1;
            }
        return res;
    }
};


int main() {

    return 0;
}
