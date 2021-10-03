/// Source : https://leetcode.com/problems/number-of-pairs-of-strings-with-concatenation-equal-to-target/
/// Author : liuyubobobo
/// Time   : 2021-10-02

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Split target + Using HashMap
/// Time Complexity: O(|t| * |nums[i].length|)
/// Space Complexity: O(n)
class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {

        int res = 0;
        map<string, int> f;

        for(const string& s: nums) f[s] ++;
        for(int len = 1; len + 1 <= target.size(); len ++){
            string a = target.substr(0, len), b = target.substr(len);
            if(a == b && f.count(a)){
                int n = f[a];
                res += n * (n - 1);
            }
            else if(a != b && f.count(a) && f.count(b))
                res += f[a] * f[b];
        }
        return res;
    }
};


int main() {

    return 0;
}
