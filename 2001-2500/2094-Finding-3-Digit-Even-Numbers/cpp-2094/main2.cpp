/// Source : https://leetcode.com/problems/finding-3-digit-even-numbers/
/// Author : liuyubobobo
/// Time   : 2021-12-04

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Check every even number between [100, 999]
/// Time Complexity: O(999)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& d) {

        vector<int> f(10, 0);
        for(int e: d) f[e] ++;

        vector<int> curf(10, 0), res;
        for(int i = 100; i <= 999; i += 2){
            fill(curf.begin(), curf.end(), 0);
            int x = i;
            while(x) curf[x % 10] ++, x /= 10;

            bool ok = true;
            for(int i = 0; i < 10; i ++)
                if(curf[i] > f[i]){ok = false; break;}
            if(ok) res.push_back(i);
        }
        return res;
    }
};


int main() {

    return 0;
}
