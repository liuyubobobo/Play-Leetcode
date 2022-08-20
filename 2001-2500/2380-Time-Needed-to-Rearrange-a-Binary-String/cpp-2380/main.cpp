/// Source : https://leetcode.com/problems/time-needed-to-rearrange-a-binary-string/
/// Author : liuyubobobo
/// Time   : 2022-08-20

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(n^2)
/// Space Complexity: O(1)
class Solution {
public:
    int secondsToRemoveOccurrences(string s) {

        int n = s.size(), res = 0;
        while(true){

            bool changed = false;
            for(int i = 0; i + 1 < n; i ++)
                if(s[i] == '0' && s[i + 1] == '1'){
                    s[i] = '1', s[i + 1] = '0';
                    i ++;
                    changed = true;
                }

            if(!changed) break;
            res ++;
        }
        return res;
    }
};


int main() {

    cout << Solution().secondsToRemoveOccurrences("0110101") << '\n';
    // 4

    return 0;
}
