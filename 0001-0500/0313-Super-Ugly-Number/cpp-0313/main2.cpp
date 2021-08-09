/// Source : https://leetcode.com/problems/super-ugly-number/
/// Author : liuyubobobo
/// Time   : 2021-08-09

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// k pointers
/// Time Complexity: O(n * |primes|)
/// Space Complexity: O(n + |primes|)
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {

        vector<int> res(n, 1);
        vector<int> pointers(primes.size(), 0);
        for(int i = 1; i < n; i ++){

            int mink = -1, minv = INT_MAX;
            for(int j = 0; j < pointers.size(); j ++)
                if(res[pointers[j]] * primes[j] < minv)
                    minv = res[pointers[j]] * primes[j], mink = j;

            res[i] = minv;
            pointers[mink] ++;

            for(int j = 0; j < pointers.size(); j ++)
                if(res[pointers[j]] * primes[j] == res[i])
                    pointers[j] ++;
        }
        return res.back();
    }
};


int main() {

    vector<int> primes1 = {2, 7, 13, 19};
    cout << Solution().nthSuperUglyNumber(12, primes1) << endl;
    // 32

    return 0;
}
