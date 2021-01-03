/// Source : https://leetcode.com/problems/count-good-meals/
/// Author : liuyubobobo
/// Time   : 2021-01-02

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Using HashMap
/// Time Complexity: O(nlogn)
/// Space Complextiy: O(n)
class Solution {

private:
    const long long MOD = 1e9 + 7;

public:
    int countPairs(vector<int>& data) {

        unordered_map<int, int> f;
        for(int e: data) f[e] ++;
        sort(data.begin(), data.end());

        int sum = 2;
        long long res = (long long)f[0] * f[1] % MOD;
        for(int i = 1; i <= 21; i ++){

            for(int e: data)
                if(e < sum / 2){
                    if(f.count(sum - e)) res += f[sum - e], res %= MOD;
                }
                else break;

            if(f.count(sum / 2))
                res += (long long)f[sum / 2] * (f[sum / 2] - 1) / 2, res %= MOD;

            sum *= 2;
        }
        return res;
    }
};


int main() {

    vector<int> data1 = {1, 3, 5, 7, 9};
    cout << Solution().countPairs(data1) << endl;
    // 4

    vector<int> data2 = {1,1,1,3,3,3,7};
    cout << Solution().countPairs(data2) << endl;
    // 15

    vector<int> data3 = {149,107,1,63,0,1,6867,1325,5611,2581,39,89,46,18,12,20,22,234};
    cout << Solution().countPairs(data3) << endl;
    // 12

    return 0;
}
