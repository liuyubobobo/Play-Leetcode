/// Source : https://leetcode.com/problems/3sum-with-multiplicity/description/
/// Author : liuyubobobo
/// Time   : 2018-10-13

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Using HashMap and Combinations
/// Using Memory Search to calculate the combinations
///
/// Try to use Dynamic Programming to get the combinations table but MLE :-(
///
/// Time Complexity: O(n^2)
/// Space Complexity: O(n^2)
class Solution {

private:
    int MOD = 1e9 + 7;

public:
    int threeSumMulti(vector<int>& A, int target) {

        map<int, int> freq;
        for(int a: A)
            freq[a] ++;

        vector<int> keys;
        for(const pair<int, int>& p: freq)
            keys.push_back(p.first);

        int res = 0;
        vector<vector<int>> comb(3001, vector<int>(3001, -1));
        for(int i = 0; i < keys.size(); i ++)
            for(int j = i; j < keys.size(); j ++){
                int a = keys[i], b = keys[j], c = target - keys[i] - keys[j];
                if(c >= b){
                    if(a == b && b == c)
                        res = (res + C(freq[a], 3, comb)) % MOD;
                    else if(a == b)
                        res = (res + (long long)C(freq[a], 2, comb) * freq[c]) % MOD;
                    else if(b == c)
                        res = (res + freq[a] * (long long)C(freq[b], 2, comb)) % MOD;
                    else
                        res = (res + freq[a] * freq[b] * freq[c]) % MOD;
                }
                else
                    break;
            }
        return res;
    }

private:
    int C(int m, int n, vector<vector<int>>& comb){

        if(n > m)
            return 0;

        if(n == 0 || m == n)
            return 1;

        if(comb[m][n] != -1)
            return comb[m][n];

        return comb[m][n] = (C(m - 1, n, comb) + C(m - 1, n - 1, comb)) % MOD;
    }
};


int main() {

    vector<int> A1 = {1,1,2,2,3,3,4,4,5,5};
    cout << Solution().threeSumMulti(A1, 8) << endl;
    // 20

    vector<int> A2 = {1,1,2,2,2,2};
    cout << Solution().threeSumMulti(A2, 5) << endl;
    // 12

    vector<int> A3(3000, 0);
    cout << Solution().threeSumMulti(A3, 0) << endl;
    // 495500972

    cout << sizeof("") << endl;
    return 0;
}