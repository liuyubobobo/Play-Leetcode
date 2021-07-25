/// Source : https://leetcode.com/problems/sum-of-digits-of-string-after-convert/
/// Author : liuyubobobo
/// Time   : 2021-07-24

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(k * |s|)
/// Space Complexity: O(|s|)
class Solution {
public:
    int getLucky(string s, int k) {

        string t = "";
        for(char c: s)
            t += to_string(c - 'a' + 1);
//        cout << res << endl;

        int sum = 0;
        while(k --){
            sum = 0;
            for(char c: t) sum += (c - '0');
            t = to_string(sum);
        }
        return sum;
    }
};


int main() {

    cout << Solution().getLucky("iiii", 1) << endl;
    // 36

    cout << Solution().getLucky("leetcode", 2) << endl;
    // 6

    cout << Solution().getLucky("zbax", 2) << endl;
    // 8

    return 0;
}
