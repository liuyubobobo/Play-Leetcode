/// Source : https://leetcode.com/problems/number-of-unique-flavors-after-sharing-k-candies/
/// Author : liuyubobobo
/// Time   : 2021-12-16

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Sliding Window
/// Time Complexity: O(n)
/// Space Complexity: O(k)
class Solution {
public:
    int shareCandies(vector<int>& candies, int k) {

        map<int, int> f;
        int n = candies.size();
        for(int i = k; i < n; i ++)
            f[candies[i]] ++;

        int res = f.size();
        for(int i = k; i < n; i ++){

            f[candies[i - k]] ++;
            f[candies[i]] --;
            if(f[candies[i]] == 0) f.erase(candies[i]);

            res = max(res, (int)f.size());
        }
        return res;
    }
};


int main() {

    return 0;
}
