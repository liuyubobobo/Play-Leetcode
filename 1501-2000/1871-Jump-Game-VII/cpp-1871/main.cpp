/// Source : https://leetcode.com/problems/jump-game-vii/
/// Author : liuyubobobo
/// Time   : 2021-05-22

#include <iostream>
#include <vector>

using namespace std;


/// Presum
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {

        s = string(maxJump, '0') + s; // deal with bounding problem
        int n = s.size();
        vector<int> data(n, 0), presum(n + 1, 0);

        data[maxJump] = 1, presum[maxJump + 1] = 1;
        for(int i = maxJump + 1; i < n; i ++){
            presum[i + 1] = presum[i];
            if(s[i] == '0'){
                int l = i - maxJump, r = i - minJump;
                if(presum[r + 1] - presum[l])
                    data[i] = 1, presum[i + 1] ++;
            }
        }
        return data.back();
    }
};


int main() {

    cout << Solution().canReach("011010", 2, 3) << endl;
    // 1

    cout << Solution().canReach("01101110", 2, 3) << endl;
    // 0

    cout << Solution().canReach("00", 1000, 1000) << endl;
    // 1

    cout << Solution().canReach("01", 1000, 1000) << endl;
    // 0

    cout << Solution().canReach("010", 1, 1) << endl;
    // 0

    cout << Solution().canReach("0" + string(1e5-2, '1') + "0", 1, 1e5 - 2) << endl;
    // 0

    cout << Solution().canReach("01010", 5, 5) << endl;
    // 0

    return 0;
}
