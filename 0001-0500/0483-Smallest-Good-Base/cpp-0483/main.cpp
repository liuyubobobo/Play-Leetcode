/// Source : https://leetcode.com/problems/smallest-good-base/
/// Author : liuyubobobo
/// Time   : 2021-06-17

#include <iostream>

using namespace std;


/// Binary Search
/// Time Complexity: O(log(n)^2 * log(LONG_LONG_MAX))
/// Space Complexity: O(1)
class Solution {
public:
    string smallestGoodBase(string n) {

        long long num = atoll(n.c_str());
        long long res = num - 1;
        for(int one_num = 3; one_num <= 60; one_num ++){
            long long base = get_base(one_num, num);
            res = min(res, base);
        }
        return to_string(res);
    }

private:
    long long get_base(int one_num, long long num){

        long long lbase = 2, rbase = num - 1;
        while(lbase <= rbase){
            long long base = (lbase + rbase) / 2;
            long long t = get_num(base, one_num);
            if(t == num) return base;
            else if(t < num) lbase = base + 1;
            else rbase = base - 1;
        }
        return LONG_LONG_MAX;
    }

    long long get_num(long long b, int one_num){

        long long res = 1ll;
        for(int i = 1; i < one_num; i ++){
            if((LONG_LONG_MAX - 1) / b < res) return LONG_LONG_MAX;
            res = res * b + 1ll;
        }
        return res;
    }
};


int main() {

    cout << Solution().smallestGoodBase("13") << endl;
    // 3

    cout << Solution().smallestGoodBase("4681") << endl;
    // 8

    cout << Solution().smallestGoodBase("1000000000000000000") << endl;
    // 999999999999999999

    cout << Solution().smallestGoodBase("2251799813685247") << endl;
    // 2

    return 0;
}
