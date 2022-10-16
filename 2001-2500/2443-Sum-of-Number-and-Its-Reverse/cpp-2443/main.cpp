/// Source : https://leetcode.com/problems/sum-of-number-and-its-reverse/
/// Author : liuyubobobo
/// Time   : 2022-10-16

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Brute Force
/// Time Complexity: O(num * log(num))
/// Space Complexity: O(log(num))
class Solution {
public:
    bool sumOfNumberAndReverse(int num) {

        for(int a = num; a >= num - a; a --){
            string a_str = to_string(a);
            reverse(a_str.begin(), a_str.end());
            int ra = atoi(a_str.c_str());
            if(ra == num - a) return true;
        }
        return false;
    }
};


int main() {

    cout << Solution().sumOfNumberAndReverse(181) << '\n';
    // 1

    return 0;
}
