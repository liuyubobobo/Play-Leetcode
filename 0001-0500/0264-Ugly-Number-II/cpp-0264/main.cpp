/// Source : https://leetcode.com/problems/ugly-number-ii/
/// Author : liuyubobobo
/// Time   : 2021-04-11

#include <iostream>
#include <set>

using namespace std;


/// Using Set
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    int nthUglyNumber(int n) {

        set<long long> set;
        set.insert(1);
        for(int i = 0; i < n - 1; i ++){
            long long x = *set.begin();
            set.erase(x);
            set.insert(x * 2);
            set.insert(x * 3);
            set.insert(x * 5);
        }
        return *set.begin();
    }
};


int main() {

    return 0;
}
