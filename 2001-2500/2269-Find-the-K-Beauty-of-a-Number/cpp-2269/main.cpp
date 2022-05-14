/// Source : https://leetcode.com/problems/find-the-k-beauty-of-a-number/
/// Author : liuyubobobo
/// Time   : 2022-05-14

#include <iostream>

using namespace std;


/// Brute Force
/// Time Complexity: O(n * k)
/// Space Complexity: O(k)
class Solution {
public:
    int divisorSubstrings(int num, int k) {

        string num_s = to_string(num);
        int res = 0;
        for(int i = 0; i + k - 1 < num_s.size(); i ++){
            int x = atoi(num_s.substr(i, k).c_str());
            if(x) res += num % x == 0;
        }
        return res;
    }
};


int main() {

    return 0;
}
