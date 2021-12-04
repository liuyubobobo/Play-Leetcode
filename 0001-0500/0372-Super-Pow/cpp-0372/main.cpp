/// Source : https://leetcode.com/problems/super-pow/
/// Author : liuyubobobo
/// Time   : 2021-12-04

#include <iostream>
#include <vector>

using namespace std;


/// Quick Pow
/// Time Complexity: O(|b|^2)
/// Space Complexity: O(|b|^2)
class Solution {

private:
    const int MOD = 1337;

public:
    int superPow(int a, vector<int>& b) {

        a %= MOD;

        if(b.empty() || (b.size() == 1 && b[0] == 0))
            return 1;
        if(b.size() == 1 && b[0] == 1)
            return a;

        vector<int> q;
        int cur = 0;
        for(int e: b){
            cur = cur * 10 + e;
            if(!q.empty() || cur / 2)
                q.push_back(cur / 2);
            cur %= 2;
        }

        int tres = superPow(a, q);
        int res = tres * tres % MOD;
        if(cur) res = res * a % MOD;
        return res;
    }
};


int main() {

    vector<int> b1 = {1, 0};
    cout << Solution().superPow(2, b1) << endl;
    // 1024

    vector<int> b2 = {2, 0, 0};
    cout << Solution().superPow(2147483647, b2) << endl;
    // 400

    return 0;
}
