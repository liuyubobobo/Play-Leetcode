/// Source : https://leetcode.com/problems/bulb-switcher-ii/description/
/// Author : liuyubobobo
/// Time   : 2017-12-02

#include <iostream>
#include <unordered_set>

using namespace std;

/// We can see the first six bulb status can decide all the sequence
/// So we can try all 2^4 operations and see how many status are there
/// for the first six bulb
///
/// Time Complexity: O(2^4)
/// Space Complexity: O(1)
class Solution {
public:
    int flipLights(int n, int m) {

        unordered_set<int> states;
        n = min(n, 6);
        for(int i = 0; i < 16 ; i++){
            int state = 0b111111;

            int onebit = onenum(i, 4);
            if(onebit > m || m % 2 != onebit % 2)
                continue;

            if(i&1)
                state ^= 0b111111;
            if(i&2)
                state ^= 0b101010;
            if(i&4)
                state ^= 0b010101;
            if(i&8)
                state ^= 0b001001;

            states.insert(state&((1<<n)-1));
        }

        return states.size();
    }

private:
    int onenum(int x, int bitnum){
        int res = 0;
        for(int i = 0 ; i < bitnum ; i ++)
            if(x&(1<<i))
                res ++;
        return res;
    }
};

int main() {

    cout << Solution().flipLights(1, 1) << endl;
    cout << Solution().flipLights(2, 1) << endl;
    cout << Solution().flipLights(3, 1) << endl;
    cout << Solution().flipLights(3, 3) << endl;
    cout << Solution().flipLights(3, 2) << endl;

    return 0;
}