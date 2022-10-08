/// Source : https://leetcode.cn/problems/1GxJYY/
/// Author : liuyubobobo
/// Time   : 2022-10-07

#include <iostream>
#include <vector>

using namespace std;


/// Sliding Window
/// Time Complexity: O(n)
/// Space Complexity: O(max(flowers))
class Solution {

private:
    const long long MOD = 1e9 + 7;

public:
    int beautifulBouquet(vector<int>& flowers, int cnt) {

        vector<int> f(100001, 0);
        int n = flowers.size(), l = 0, r = -1;
        long long res = 0;
        while(l < n){
            if(r + 1 < n && f[flowers[r + 1]] + 1 <= cnt){
                f[flowers[++ r]] ++;
                res = (res + 1) % MOD;
            }
            else{
                f[flowers[l ++]] --;
                res = (res + (r - l + 1)) % MOD;
            }
        }
        return res;
    }
};


int main() {

    return 0;
}
