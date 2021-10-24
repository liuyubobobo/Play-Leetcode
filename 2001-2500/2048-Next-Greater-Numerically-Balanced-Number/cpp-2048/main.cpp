/// Source : https://leetcode.com/problems/next-greater-numerically-balanced-number/
/// Author : liuyubobobo
/// Time   : 2021-10-23

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    int nextBeautifulNumber(int n) {

        for(int x = n + 1;;x ++)
            if(ok(x)) return x;
        assert(false);
        return -1;
    }

private:
    bool ok(int x){

        vector<int> f(10, 0);
        while(x) f[x % 10] ++, x /= 10;

        if(f[0]) return false;
        for(int i = 1; i < 10; i ++)
            if(f[i] && f[i] != i) return false;
        return true;
    }
};


int main() {

    cout << Solution().nextBeautifulNumber(1) << endl;
    // 22

    cout << Solution().nextBeautifulNumber(1000) << endl;
    // 1333

    cout << Solution().nextBeautifulNumber(3000) << endl;
    // 3133

    return 0;
}
