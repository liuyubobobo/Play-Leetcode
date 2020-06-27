/// Source : https://leetcode.com/problems/the-kth-factor-of-n/
/// Author : liuyubobobo
/// Time   : 2020-06-27

#include <iostream>
#include <vector>

using namespace std;


/// Just calculate all the factors once
/// Time Complexity: O(sqrt(n))
/// Space Complexity: O(n)
class Solution {
public:
    int kthFactor(int n, int k) {

        vector<int> factors;
        for(int i = 1; i * i <= n; i ++)
            if(n % i == 0){
                k --;
                if(!k) return i;
                if(i * i != n) factors.push_back(n / i);
            }
        return k - 1 < factors.size() ? factors[factors.size() - k] : -1;
    }
};


int main() {

    return 0;
}
