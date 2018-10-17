/// Source : https://leetcode.com/problems/3sum-with-multiplicity/description/
/// Author : liuyubobobo
/// Time   : 2018-10-15

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Using HashMap and Combinations
/// Since we ony use combination numbers like C(n, 2) or C(n, 3),
/// There's no need to calculate the n * n combination tables,
/// We calculate a n * 3 combination table instead :-)
///
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {

private:
    int MOD = 1e9 + 7;

public:
    int threeSumMulti(vector<int>& A, int target) {

        vector<vector<int>> C = calcC(A.size());

        map<int, int> freq;
        for(int a: A)
            freq[a] ++;

        vector<int> keys;
        for(const pair<int, int>& p: freq)
            keys.push_back(p.first);

        int res = 0;
        for(int i = 0; i < keys.size(); i ++)
            for(int j = i; j < keys.size(); j ++){
                int a = keys[i], b = keys[j], c = target - keys[i] - keys[j];
                if(c >= b){
                    if(a == b && b == c)
                        res = (res + C[freq[a]][3]) % MOD;
                    else if(a == b)
                        res = (res + (long long)C[freq[a]][2] * freq[c]) % MOD;
                    else if(b == c)
                        res = (res + freq[a] * (long long)C[freq[b]][2]) % MOD;
                    else
                        res = (res + freq[a] * freq[b] * freq[c]) % MOD;
                }
                else
                    break;
            }
        return res;
    }

private:
    vector<vector<int>> calcC(int n){

        vector<vector<int>> C(n + 1, vector<int>(4, 0));
        C[0][0] = 1;
        for(int i = 1; i <= n; i ++){
            C[i][0] = 1;
            for(int j = 1; j <= 4; j ++)
                C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
        }
        return C;
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

    return 0;
}