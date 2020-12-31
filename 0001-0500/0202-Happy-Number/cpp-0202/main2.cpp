/// Source : https://leetcode.com/problems/happy-number/
/// Author : liuyubobobo
/// Time   : 2020-04-03

#include <iostream>

using namespace std;

/// Floyd's Cycle-Finding Algorithm
/// Time Complexity: O(logn)
/// Space Complexity: O(1)
class Solution {
public:
    bool isHappy(int n) {

        if(n == 1) return true;

        int slow = op(n); if(slow == 1) return true;
        int fast =op(slow); if(fast == 1) return true;
        while(slow != fast){
            slow = op(slow);
            fast = op(fast); if(fast == 1) return true;
            fast = op(fast); if(fast == 1) return true;
        }

        return false;
    }

private:
    int op(int x){
        int res = 0;
        while(x){
            int t = x % 10;
            res += t * t;
            x /= 10;
        }
        return res;
    }
};


void print_bool(bool res){

    cout << (res ? "True" : "False") << endl;
}

int main() {

    print_bool(Solution().isHappy(19));
    // true

    return 0;
}