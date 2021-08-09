/// Source : https://leetcode.com/problems/super-ugly-number/
/// Author : liuyubobobo
/// Time   : 2021-08-09

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Tree Set
/// Time Complexity: O(nlogn * |primes|)
/// Space Complexity: O(n)
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {

        set<int> set;
        set.insert(1);
        int index = 0;
        while(!set.empty()){
            int cur = *set.begin(); set.erase(set.begin());
            index ++;
            if(index == n) return cur;

            for(int p: primes)
                if(INT_MAX / cur >= p)
                    set.insert(cur * p);
        }

        assert(false);
        return -1;
    }
};


int main() {

    vector<int> primes1 = {2, 7, 13, 19};
    cout << Solution().nthSuperUglyNumber(12, primes1) << endl;
    // 32

    return 0;
}
