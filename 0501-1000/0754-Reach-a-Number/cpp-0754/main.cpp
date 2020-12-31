/// Source : https://leetcode.com/problems/reach-a-number/
/// Author : liuyubobobo
/// Time   : 2020-04-23

#include <iostream>

using namespace std;


/// Mathematics
/// See here for details: https://leetcode.com/problems/reach-a-number/solution/
/// Time Complexity: O(sqrt(n))
/// Space Complexity: O(1)
class Solution {
public:
    int reachNumber(int target) {

        if(target < 0) target = -target;

        int sum = 0, k = 1;
        while(sum < target) sum += k ++;

        if(sum == target || (sum - target) % 2 == 0) return k - 1;
        for(;;){
            sum += k ++;
            if((sum - target) % 2 == 0) return k - 1;
        }
        return -1;
    }
};


int main() {

    cout << Solution().reachNumber(4) << endl;
    // 3

    cout << Solution().reachNumber(5) << endl;
    // 5

    return 0;
}
