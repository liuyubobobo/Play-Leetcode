/// Source : https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/
/// Author : liuyubobobo
/// Time   : 2021-08-09

#include <iostream>
#include <vector>

using namespace std;


/// Two Pointers
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int minSwaps(string s) {

        int n = s.size(), l = 0, r = n - 1;
        int stack1 = 0, stack2 = 0, res = 0;
        while(l <= r){
            for(; l <= r; l ++){
                if(s[l] == '[') stack1 ++;
                else stack1 --;
                if(stack1 < 0) break;
            }

            for(; r >= l; r --){
                if(s[r] == ']') stack2 ++;
                else stack2 --;
                if(stack2 < 0) break;
            }

            if(l <= r){
                swap(s[l], s[r]);
                l ++, r --;
                res ++;
                stack1 += 2, stack2 += 2;
            }
            else break;
        }
        return res;
    }
};


int main() {

    cout << Solution().minSwaps("][][") << endl;
    // 1

    cout << Solution().minSwaps("]]][[[") << endl;
    // 2

    cout << Solution().minSwaps("[]") << endl;
    // 0

    return 0;
}
