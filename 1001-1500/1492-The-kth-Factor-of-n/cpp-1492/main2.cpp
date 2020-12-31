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
        for(int i = 1; i * i <= n; i ++) // 使用 i * i <= n，避免 sqrt(n) 运算的性能和精度问题
            if(n % i == 0){
                factors.push_back(i);

                // 对于 i * i == n 的情况要进行以下判断，
                // 如果 i * i == n，则 i 和 n / i 是一个数字，不能重复添加进 factors
                if(i * i != n)
                    factors.push_back(n / i);
            }
        sort(factors.begin(), factors.end());
        return k - 1 < factors.size() ? factors[k - 1] : -1;
    }
};


int main() {

    return 0;
}
