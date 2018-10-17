/// Source : https://leetcode.com/problems/3sum-with-multiplicity/description/
/// Author : liuyubobobo
/// Time   : 2018-10-15

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Using HashMap and Combinations
/// Since we ony use combination numbers like C(n, 2) or C(n, 3),
/// There's no need to calculate any combination tables, actually :-)
///
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
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
        for(int i = 0; i < keys.size(); i ++)
            for(int j = i; j < keys.size(); j ++){
                int a = keys[i], b = keys[j], c = target - keys[i] - keys[j];
                if(c >= b){
                    if(a == b && b == c && freq[a] >= 3){
                        long long C = ((long long)freq[a] * (freq[a] - 1) * (freq[a] - 2) / 6) % (long long)MOD;
                        res = (res + C) % MOD;
                    }
                    else if(a == b && b != c && freq[a] >= 2){
                        long long C = freq[a] * (freq[a] - 1) / 2;
                        res = (res + C * freq[c]) % MOD;
                        continue;
                    }
                    else if(b == c && a != b && freq[b] >= 2){
                        long long C = freq[b] * (freq[b] - 1) / 2;
                        res = (res + freq[a] * C) % MOD;
                        continue;
                    }
                    else if(a != b && b != c)
                        res = (res + freq[a] * freq[b] * freq[c]) % MOD;
                }
                else
                    break;
            }
        return res;
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

    vector<int> A4 = {2, 1, 3};
    cout << Solution().threeSumMulti(A4, 6) << endl;
    // 1

    vector<int> A5 = {3, 3, 0, 0, 3, 2, 2, 3};
    cout << Solution().threeSumMulti(A5, 6) << endl;
    // 12

    return 0;
}